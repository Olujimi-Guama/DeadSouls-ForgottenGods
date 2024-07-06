#include <lib.h>
#include "../areadefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("the void");
    SetLong("The void.  Go down to get out.");
    SetExits( ([ "down" : STARTROOM ]) );
    SetNoModify(1);
}
void init(){
    ::init();
}
