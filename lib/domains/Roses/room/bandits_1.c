#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {
    
    ::create();
    
    SetShort("BLANK_ROOM");
    SetLong("~~DOCKS ARE UNDER MARTIAL LAW~~~");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    
    SetExits(([
        "west" : MY_ROOM "/beggars_3",
      ]));
}

void init(){
    ::init();
}