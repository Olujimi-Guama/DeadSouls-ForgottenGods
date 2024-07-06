#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {
    ::create();
    
    SetShort("BLANK_ROOM");
    SetLong("The Razors Edge Shop is here.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetExits(([
        "north" : MY_ROOM "/bridge_reid",	
        "east" : MY_ROOM "/barracks_e",
        "west" : MY_ROOM "/beggars_1",
      ]));
}

void init(){
    ::init();
}
