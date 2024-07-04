#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;


void create() {
    ::create();

    SetAmbientLight(0);
    SetShort("commander's quarters");
    SetLong(
      "This is a dark underground room. The walls are rough and bare. "
      "A passageway leads away to the south."
    );
    SetItems(([
        ({ "passage", "passageway" }) : "This provides access to areas "
        "below the ground.",
        ({ "ground", "rock", "rocks", "earth", "dirt", "stone", "stones" }) :
        "Rough and dirty, as one would expect from a simple "
        "underground area.",
        ({ "wall", "walls", "rough walls", "rough and bare walls",
          "bare walls", "bare and rough walls" }) : "Carved roughly into "
        "the earth, this passageway has walls that expose "
        "underground rock. Clearly this area was architected with "
        "utility and expediency in mind.",
      ]));
    SetInventory(([
        NPC+ "kurogane" : 1,
        OBJ+ "tall_lamp" : 1,
        OBJ+ "table" : 1,
        OBJ+ "chest0" : 1,
        OBJ+ "cot" : 1,
      ]));
    SetExits(([
        "south" : ROOM+ "guardroom2",
      ]));
    SetDoor("south", ROOM+ "kurogane.c");

}

void init(){
    ::init();
}
