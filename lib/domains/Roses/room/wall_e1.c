//	Elohim Feb 2010
//  	Advanced Room search, adding enters, and item description handling

#include <lib.h>
#include <damage_types.h>
#include "../areadefs.h"

inherit MROOM;

string findDoor();
string rubbleDESC();
string gatehouseDESC();
int mngItems();
int fallingRubble(object);
int _flag = 0;
int queryRubble(){ return _flag; };

//	Room Description Modified
string longDESC(){

    string corelong = "The gate tower stretches high above seperating the "
    "wall and the gates. Here, rubble and debris have been collected and "
    "piled haplessly in this locale. Some of the remains of the upper "
    "damaged sections of the wall have been been picked away and "
    "hauled off for materials. ";
    string flagOff = "A large pile of rubble is gathered before the gate tower.";
    string flagOn = "A path has been cleared leading to the gatehouse.";

    if(!_flag) return corelong+flagOff;
    else return corelong+flagOn;
}

string rubbleDESC(){

    //	see SetItems() for trigger
    //	advanced string handling for one item

    string coreitem = "Large sections of stone and wood have been "
    "piled and collected in this general area on Wall. \n";
    string flagOff = "No one monitors this rubble and there's no telling what "
    "can be found if searched thoroughly. \n";
    string flagOn = "Someone has meticulously cleared a path through the "
    "rubble. You observe an entrance to the gatehouse that you can enter. \n";

    if(!_flag) return coreitem+flagOff;
    else return coreitem+flagOn;
}

string gatehouseDESC(){

    //	see SetItems() for trigger
    //	advanced string handling for one item

    if(!_flag) return "You visually follow the tower "
        "down to the ground looking for a gatehouse but cannot see any evidence "
        "of it due to all the rubble. Not having any tools for proper excavation, you "
        "realize you will have to search through the rubble to satisfy your "
        "curiosities." ;
    else return "The gatehouse sits at the base of the tower. Before it the "
        "rubble has been cleared. \n";
}

static void create() {

    ::create();

    SetShort("Eastgate Tower");
    SetLong( (:longDESC:) );
    SetItems( ([
        ({"rubbish", "remains","rubble"}) : (: rubbleDESC :),
        ({"gatehouse", "gate house","tower base",
          "base of the tower"}) : (: gatehouseDESC :),
        ({"gate tower","gate towers","gatetower"}) : 
        "The tower rises high supporting the town gates "
        "here to the east and the paraport above.",
        "paraport" : "The paraport high above has been abandoned for "
        "many years.",
        "wall" : "The wall here stretches to the east.",
        ({"gate","gates"}) : "The city gates span the opening "
        "between the two gate towers.",
        "locale" : "This place seems to serve as the rubble depository.",
        ({"upper damaged sections","upper damaged section",
          "upper sections","upper section","damaged sections",
          "damaged section"}) : "Sections of the wall still crumble to this "
        "day. The rubble is collected in piles around its base.",
        ({"materials","material","wood","stone"}) : "Pieces of wood "
        "and stone left here are unfit to reuse elsewhere."		
      ]) );
    SetExits(([
        "east" : MY_ROOM "/wall_e2",
        "west" : MY_ROOM "/merchant_n2"
      ]));
}


void init(){
    ::init();

    if(!_flag) AddSearch( ({"rubbish", "remains","rubble"}), (: findDoor :) );
}


void reset(){

    fallingRubble(this_object()); //this sets flag to 0


    ::reset();
}


string findDoor(object player, string str){


    object rroom = find_object("/domains/Roses/room/eastgate_f1");
    object penv = environment(player);
    string pname = player->GetCapName();
    int diceroll = random(100);

    message("say",
      "\nYou start fumbling around the rubble "
      " hoping to find something worthwhile.\n",
      player );
    message("say",
      "\n"+pname+" starts fumbling around the rubble ",
      this_object(), player );

    if( diceroll >75 ){

        _flag++; 

        RemoveSearch("rubbish");
        RemoveSearch("remains");
        RemoveSearch("rubble");

        RemoveItem("pile");
        RemoveItem("large pile");
        RemoveItem("large pile of rubble");

        AddItem("path", "A path has been cleared through the "
          "rubble towards the gatehouse.");
        AddItem( ({"gatehouse entrance",
            "entrance to the gatehouse"}), "Enter guardhouse to "
          "explore the abandoned chambers of the gate tower. " );  

        AddEnter("gatehouse", MY_ROOM "/eastgate_f1");

        message("say",
          "\n"+pname+" clears the rubble and finds an entrance to the tower!",
          this_object(), player );

        if(rroom)
            message("say",
              "The rubble blocking the door has been cleared!\n",
              rroom );

        return "\nYou clear a path to the tower going through the rubble and "
        "discover an entrance.";
    }

    message("say",
      "\n"+pname+" fumbles around and finds nothing.",
      this_object(), player );
    return "You fumble around in the open and find nothing.";
}

int fallingRubble(object room){ 

    object rroom = find_object("/domains/Roses/room/eastgate_f1");
    object *temparr,*stuff,*lstuff;
    string *limbs = ({});
    int i, ii;


    if (!room->IsRoom()){
        message("say", "Error ["+(string)this_object()+"]: expected room obj "
          "in function fallingRubble(). Please use <bug> to report.\n", 
          room );
        return 0;
    }

    tell_room(room, 
      "BOLD%^%^YELLOW%^Rubble and debris tumbles down from above! \n%^RESET%^");
    if(rroom)
        tell_room(rroom, 
          "BOLD%^%^YELLOW%^Waves of dust fills the air as rubble falls from "
          "above, effectively blocking your exit!\n%^RESET%^");
    stuff=all_inventory(room);
    lstuff = ({});

    for(i=0;i<sizeof(stuff);i++){
        temparr= ({ stuff[i] });
        if(living(stuff[i]) && !sizeof(lstuff)) lstuff = ({stuff[i]});
        if(living(stuff[i]) && sizeof(lstuff) > 0 
          && member_array(stuff[i],lstuff) == -1) lstuff += ({stuff[i]});
    }

    for(i=0;i<sizeof(lstuff);i++){ 
        if(sizeof(lstuff) > 0 ) {  //removed  && !creatorp(lstuff[i])
            ii = random(sizeof(limbs = lstuff[i]->GetLimbs()));
            lstuff[i]->eventReceiveDamage(BLUNT, 7,random(30)+10, limbs[ii]);

            message("say",
              "\nA random stone lands right on your "+limbs[ii]+", OUCH!\n",
              lstuff[i] );
        }
    }

    _flag = 0;

    RemoveEnter("gatehouse");
    RemoveItem("gatehouse entrance");
    RemoveItem("entrance to the gatehouse");
    RemoveItem("path");		
    AddItem( ({"pile","large pile","large pile of rubble"}), "A large pile of "
      "rubble from the upper sections of the wall has been gathered "
      "here in a large pile.");
    AddSearch( ({"rubbish", "remains","rubble"}), (: findDoor :)	); //for the benefit of present players	

    return 1;
}
