/*	
 *	Elohim 201104@Forgotten Gods.mud
 *	Rez room for ghost players
 *	confession system in the works
 */	


#include <lib.h>
#include "../areadefs.h"

inherit MROOM;


int lookItem(string str);
int begConfession();
int revivePlayer(string str);
string extendedRoomDesc();

mapping judges = ([ ]);
object *sinners = ({ });

mapping GetJudges(){ return judges; }
object *GetSinners(){ return sinners; }



void create() {
    ::create();

    SetProperties( ([
        "consecrated" : 1,
        "no attack" : 1,
        "no steal" : 1,
        "no castle" : 1
      ]) );    

    SetClimate("indoors");
    SetShort( "All Faith Monastery");
    SetLong( (:extendedRoomDesc() :) );		
    SetExits( ([
        "west" : MY_ROOM "/courtyard",
        "south" : MY_ROOM "/clergy",
        "out" : MY_ROOM "/bridge_voss"
      ]) );

    SetItems( ([
        ({"monastery","local monastery","temple",
          "simple temple","here"}) : "You are here.",
        ({"center","mats"}) : "They are arranged in a "
        "circle in the center.",
        "center" : "The mats are arranged in a circle around "
        "the center.",
        "walls" : "There is nothing noteworthy here.",
        ({"tapestry","tapestries"}) : "The tapestries were "
        "brought in from around the world representing "
        "all the factions that maintain the monastary",
        ({"faction","factions"}) : "They are represented in the "
        "tapestries.",
        ({"establishment","humble establishment"}) : 
        "You look the monastary over.",
        ({"members","Visiting members","member",
          "visiting member"}) : "Members of representing "
        "factions frequent this temple.",
        ({"monastery's courtyard","courtyard"}) : 
        "To the east you see the monastery's courtyard.",	  
        //	from SetListen()
        ({"default","chants","chanting"}) : 
        "Your ears are not trained well enough "
        "to pull that off."
      ]) );
    SetListen( ([
        "default" : "You hear chants coming "
        "from the courtyard.",
        "courtyard" : "You hear the chanting of monks.",
        ({"chants","chanting"}) : "The hollow sounds of "
        "AUM resonates through the air.",
        ({"universe","AUM"}) : "The purest sound echoing "
        "from the universe."
      ]) );

}




void init() {
    ::init();

    //	override look/exa
    add_action( (:lookItem:), ({"look","examine"}) );
    add_action( (:begConfession:), "confess" );
    add_action( (:revivePlayer:), "pray" );
}


string extendedRoomDesc(){

    object tp = this_player();
    string religion = tp->GetReligion();

    string roomDesc = 
    "You are in the local monastery where all of faith "
    "are welcomed to observe thier religious "
    "beliefs. It is maintained by those who seek "
    "shelter with-in these walls. Mats are arranged "
    "in a circle around the center of this simple temple. "
    "The walls are decorated with tapestries representing  "
    "different factions that support this humble "
    "establishment. \n"
    "Visiting members of the religious communities "
    "offer thier services to anyone wanting to "
    "confess past sins. It is said that those who "
    "come to an untimely end offer prayer to the "
    "gods for ressurection.";

    //	Dead Players (ghost) see in the spirtual realm
    if( tp->GetGhost() ){

        roomDesc = 
        "You arrive at the local monastery but it all "
        "seems wrong. Your spectral eyes witnesses "
        "a vortex of spiritual energy being funneled "
        "into the center of the monastery where a "
        "chained figure appears to be imprisoned. \n\n";


        //	Religion based long description. 
        //	Text files are stored in ../txt/religion/ directory
        if( religion && file_exists(religion = 
            MY_REL "/ResurrectionDesc_"+religion+".txt") ){				
            roomDesc += read_file(religion);
            return roomDesc;
        }

        roomDesc += 
        "As so many others before you, being "
        "hopeless and desperate, you feel you "
        "must %^CYAN%^BOLD%^<pray>"
        "%^RESET%^ to save your eternally "
        "damned soul.";
    }

    return roomDesc;
}


int lookItem(string str){

    //	this can be expanded on
    if(str && this_player()->is_ghost() ){


        // catchall for the coditional
        write("There is too much spiritual energy "
          "roaring in this place to focus on anything.");
        return 1;
    }

    return 0;
}


int begConfession(string str){

    int i;
    object tp = this_player();
    object here = this_object();
    object *inv;


    i = sizeof(inv = all_inventory(here));

    while(i--) 
        if( inv[i]!=tp && 
          living(inv[i])  && 
          ( inv[i]->query_class() == "monk" ||
            inv[i]->query_class() == "cleric" ) ){

            judges[inv[i]] = time();
        }

    if( sizeof(keys(judges)) ){

        if( member_array(tp, sinners) == -1 )
            sinners += ({tp});

        write("You confess your wicked ways "
          "to anyone who would listen.");
        say(tp->GetCapName()+
          " confesses thier wicked ways "
          "to anyone who would listen.");
        //call_out("forgive", 60, tp);				
        return 1;
    }

    notify_fail("There is no one here to listen "
      "to your confessions.");
    return 0;
}


int revivePlayer(string str) {

    object tp = this_player();   

    if(!tp->GetGhost()){
        write("The living do not need to pray for revival.\n");
        say(tp->GetCapName()+" utters a prayer. \n");
        return 1;
    }


    if( !tp->indirect_resurrect_obj() ){
        write("Your prayers are denied. \n");
        say("You hear a ghostly wail. \n");
        return 1;
    }


    message("my_action",
      "A whirlwind of raw energy engulfs your ghost, "
      "attaching it to flesh anew. \n",
      tp );
    message("other_action",
      "A sudden whirlwind of raw energy coalesces into "
      +tp->GetCapName()+". \n",
      environment(tp), tp );

    tp->eventRevive();

    return 1;
}
/*
int confess(string str) {

object *inv;
int i, ok;
string res;

if(str != "murder") {
notify_fail("Confess what?\n");
return 0;
}
ok = 0;
if(sscanf(this_player()->getenv("TITLE"), "%s murderer $N%*s", res)
!= 1) {

notify_fail("You are no murderer.\n");

return 0;
}

i = sizeof(inv = all_inventory(this_object()));

while(i--) if(inv[i]->query_class() == "monk") ok = 1;

if(!ok) {
write("There is no one here to whom you may confess.");
return 1;
}
message("my_action", "You beg the monks for forgiveness for "
"your murder of a "+lower_case(res)+".", this_player());
message("my_action", ("You pray that forgiveness does not mean "
"death."), this_player());
say(this_player()->query_cap_name()+" begs for "+
this_player()->query_possessive()+" murder of a "+
lower_case(str)+".");
begging += ({ this_player() });
call_out("forgive", 60, this_player());
return 1;
}

object *query_forgiven() { return begging; }

void forgive(object ob) {
string tmp;

if(member_array(ob, begging) == -1) return;
begging -= ({ ob });
tmp = call_other("/domains/Praxis/"+ob->query_class()+"_hall",
"get_new_title", ob);
message("info", "You are now forgiven.", ob);
ob->setenv("TITLE", tmp);
ob->add_mp(-500);
ob->add_hp(100- (ob->query_skill("faith")));
}
*/
