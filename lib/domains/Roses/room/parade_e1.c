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
        "west" : MY_ROOM "/_square",
        "east" : MY_ROOM "/parade_e2"
      ]));
    
}

void init(){
    ::init();
}
