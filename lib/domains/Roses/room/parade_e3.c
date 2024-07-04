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
        "west" : MY_ROOM "/parade_e2",
        "north" : MY_ROOM "/enclave"
      ]));
    
}

void init(){
    ::init();
}
