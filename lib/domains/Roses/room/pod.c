#include <lib.h>
#include "../areadefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("the incept pod");
    SetLong("The incept pod. Some objects come here to be created "+
      "and identified. Go down to get out.");
    SetExits( ([ "down" : STARTROOM ]) );
}
int CanReceive(object ob){
    return room::CanReceive(ob);
}
