#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;


void create() {
    ::create();

    SetAmbientLight(0);
    SetShort("troll pit");
    SetLong(
      "This is a dark underground pit. The walls are rough "
      "and covered in withered vines. "
      //"A passageway leads southwest."
    );
    SetItems(([
        ({ "ground", "rock", "rocks", "earth", "dirt", "stone", 
          "stones" }) : "Rough and dirty, as one would expect from "
        "a simple underground area.",
        ({ "wall", "walls", "rough walls", "rough and bare walls", 
          "bare walls", "bare and rough walls" }) : "Carved roughly "
        "into the earth, this passageway has walls that expose "
        "underground rock. Clearly this area was architected "
        "with utility and expediency in mind.",
        ({ "passage", "passageway" }) : "This provides access "
        "to areas below the ground.",
        ({ "room", "here", "area" }) : "Carved roughly into the "
        "earth, this area has walls that expose underground rock.",
      ]));
    SetInventory(([
        ETC+ "vines" : 1,
        NPC+ "cavetroll" : 1,
      ]));

    // Connecting Area is not in the game yet. 

    //SetDoor("southwest", "/domains/town/doors/gate.c");
    SetExits( ([ 
        //"southwest" : "/domains/town/room/wtunnel6",
      ]) );

    // Converted Fly to Climb function
    //SetFlyRoom("/domains/cave/room/chieftain");
    // SetFlowLimit(2);
}

void init(){
    ::init();
}

