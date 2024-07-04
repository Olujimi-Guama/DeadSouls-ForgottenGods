#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;


void create() {
    ::create();

    SetAmbientLight(5);
    SetShort("underground passageway");
    SetLong(
      "This is a dark underground passageway. The walls are rough "
      "and bare. The passageway runs east and west. There are "
      "rooms to the north and south."
    );
    SetItems(([
        ({ "passage", "passageway"}) : "This provides access "
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
    SetExits( ([
        "north" : ROOM+ "guardroom2",
        "south" : ROOM+ "food_storage1",
        "west" : ROOM+ "cavepass5",
        "east" : ROOM+ "cavepass12.c",
      ]) );

    SetInventory(([
      ]));

    SetDoor("south", DOORS+ "food_storage1");
}

void init(){
    ::init();
}

