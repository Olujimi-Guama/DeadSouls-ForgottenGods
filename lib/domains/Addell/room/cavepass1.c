#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;

int preExit();
int postExit();
int bouncer();
mapping exfunVal=([]);


mapping roomDebug(){return exfunVal;}

void create() {
    ::create();

    SetAmbientLight(5);
    SetShort("underground passageway");
    SetLong(
      "You step into a dimly lit cave pass. The walls are rough and "
      "uneven, covered in patches of slimy moss that glisten in the "
      "faint light. Stalactites hang precariously from the ceiling, "
      "dripping water into shallow, muddy puddles on the ground. The "
      "floor is uneven and treacherous, littered with jagged rocks "
      "and the occasional bone, hinting at the cave's grim "
      "inhabitants. To the west the passage opens up into a cave-"
      "like area. The passageway continues northeast and east from "
      "here."
      );
    SetSmell( ([
      ({"default", "stench"}) : "The air is thick with the stench of "
      "mildew and the earthy scent of damp soil.",
      "mildew" : "",
      ({"earthly scent", "scent", "damp soil", "soil"}) : ""
      ]) );
    SetListen( ([ 
      ({"default", "symphony of sound", "sound", "cavern"}) : 
      "You hear the guttural grunts of cave orcs and the clinking of "
      "their crude weapons echoing through the cavern, creating an "
      "unsettling symphony of sound.",
      ({"gutteral grunts", "grunts", "grunt"}) : "",
      ({"clinking", "clink", "crude weapons", "crude weapon", 
      "weapons", "weapon", "echoing", "echo"}) : "",
      ]) );
    SetItems( ([
        ({ "pass", "cave pass"}) : "This provides access "
        "to areas below the ground.",
        ({ "area", "cave like area", "cavelike area" }) : "It "
        "seems that to the west there is a n area like a cave "
        "which opens up to the outside.",
        ({ "ground", "rock", "rocks", "earth", "dirt", "stone", 
          "stones" }) : "Rough and dirty, as one would expect "
        "from a simple underground area.",
        ({ "wall", "walls", "rough walls", "rough and bare walls", 
          "bare walls", "bare and rough walls" }) : "Carved roughly "
        "into the earth, this passageway has walls that expose "
        "underground rock. Clearly this area was architected "
        "with utility and expediency in mind."
      ]));
    SetInventory(([
        NPC+ "orc_guard" : 1,
      ]));
    SetClimate("indoors");
    SetExits( ([
        "east" : ROOM+ "cavepass2",
        "northeast" : ROOM+ "cavepass3.c"
      ]) );
    AddExit( "west", 
      ZONE_START, (: preExit :), (: postExit :));
}

int bouncer(object ob){

    string *cdwellers = ({ "cavetroll", "chieftain", "gorm", 
      "kurogane", "orc_guard", "orc_soldier", "rat", "rybak" });

    if(!ob)error("Expected \'Object\' got \'0\'");

    if(member_array( explode(
          base_name(ob),"/")[3],cdwellers) !=-1) return 0;

    else return 1;
}

int preExit(){

    object ob = this_player(), rN;

    if(bouncer(ob))return 1;

    exfunVal["npc"] = ob;
    exfunVal["player"] = (rN = ob->GetLeader());
    exfunVal["origin"] = this_object();
    exfunVal["destination"] = load_object(ZONE_START);


    if(rN){		

        message("other_action", rN->GetName()+
          " is pursued after by a raging "+
          ob->GetName()+".",
          this_object());
    }

    else{	
        message("other_action", 
          "The "+ob->GetKeyName()+
          " peers out to the grotto entrance.",
          this_object());
        message("other_action", "You catch a glimpse of "+
          add_article(ob->GetShort())+
          " peering out from inside the darkness of the grotto.",
          load_object(ZONE_START));
    }

    return 0;
}

int postExit(){

    object ob=exfunVal["npc"];
    object rN=exfunVal["player"];
    object fr=exfunVal["origin"];
    object to=exfunVal["destination"];

    if(rN && this_player()==rN && !bouncer(ob)){	

        ob->eventQuell();
        rN->eventQuell();
        rN->RemoveFollower(ob);

        message("my_action", 
          "You outrun the "+ob->GetName()+
          " to safety knowing that it is lying "
          "in wait back in the shadows of the grotto.",
          rN);	
        message("other_action", 
          rN->GetName()+" outruns a pursuing "+ob->
          GetName()+". It returns angrily to the grotto.",
          to, rN);
        message("other_action", "The "+ob->GetName()+
          " returns angrily to the grotto after losing its quarry.",
          fr, rN);
    }

    exfunVal = ([]);
    return 1;
}

void init(){
    ::init();
}
