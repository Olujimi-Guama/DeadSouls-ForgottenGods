#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit ROOM_VOID;


void create() {
    ::create();
    SetAmbientLight(30);
    SetShort("the void");
    SetLong("The void.  Go down to get out.");
    SetExits( ([ "down" : ZONE_START ]) );
    SetNoModify(1);
}
void init(){
    ::init();
}
