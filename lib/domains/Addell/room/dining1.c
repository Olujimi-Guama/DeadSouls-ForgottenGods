#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;


void create() {
    ::create();

    SetAmbientLight(0);
    SetShort("post commissary");
    SetLong(
      "This is a dark underground room with rough walls. It is "
      "outfitted to accommodate personnel who want to eat "
      "and drink. Passageways lead north, east, and south from "
      "here."
    );
    SetItems(([
        ({ "passage", "passageway", "This provides access to areas below the ground." }) : "This provides access to areas below the ground.",
        ({ "ground", "rock", "rocks", "earth", "dirt", "stone", "stones" }) : "Rough and dirty, as one would expect from a simple underground area.",
        ({ "wall", "walls", "rough walls", "rough and bare walls", "bare walls", "bare and rough walls" }) : "Carved roughly into the earth, this passageway has walls that expose underground rock. Clearly this area was architected with utility and expediency in mind.",
      ]));
    SetInventory(([
        OBJ+ "tall_lamp" : 1,
        OBJ+ "chair" : 2 + random(3),
        OBJ+ "table2" : 1,
        OBJ+ "rack" : 1,
        OBJ+ "lister" : 1,
        OBJ+ "cask" : 1        
      ]));
    SetClimate("indoors");
    SetExits( ([
        "south" : ROOM+ "cavepass12",
        "east" : ROOM+ "cavepass9",
        "north" : ROOM+ "cavepass8.c",
      ]) );

}

void init(){
    ::init();
}

