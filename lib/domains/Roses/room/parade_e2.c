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
        "east" : MY_ROOM "/parade_e3",
        "west" : MY_ROOM "/parade_e1",
        
      ]));
    
}

void init(){
    ::init();
}
