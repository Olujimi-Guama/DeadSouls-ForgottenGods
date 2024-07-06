#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;

void create() {
    ::create();


    SetCoordinates("999000,999000,999000"); 
    SetShort("cave entrance");
    SetLong("This is a small cave near a riverbank.");
    SetNightLong("This is a cave carved into the "
      "rocky riverbank wall. The cave opens west "
      "into the night. To the east is darkness.");
    SetDayLong("This is a cave carved into the rocky "
      "riverbank wall. Daylight shines in from the "
      "west, where the river flows. To the east, "
      "the cave continues into darkness.");
    SetItems(([
        ({ "wall", "rocky wall", "river bank wall", 
          "riverbank wall", "rocky river bank wall", 
          "rocky riverbank wall" }) : "The local river "
        "carved a narrow and steep valley here over "
        "the years. The walls of that valley is what "
        "this cave has been dug out of.",
      ]));
    SetExits( ([
        //"west" : ROOM+ "riverbank",
        "east" : ROOM+ "cavepass1",
      ]) );
    SetInventory( ([
        ETC+ "portal_out" : 1
      ]) );
}

void init(){
    ::init();
}
