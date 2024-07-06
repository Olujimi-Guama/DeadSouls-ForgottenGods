#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {
    ::create();
    
    
    SetShort("BLANK_ROOM");
    SetLong("THIS ROOM NEEDS ATTENTION");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    
    SetExits(([
        "east" : MY_ROOM "/merchant_s1",
        "south" : MY_ROOM "/beggars_2"
      ]));	
}

void init(){
    ::init();
}
