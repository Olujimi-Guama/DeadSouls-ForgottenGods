#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;


void create() {
    ::create();
    SetAmbientLight(30);
    SetShort("the incept pod");
    SetLong("The incept pod. Some objects come here to be created "+
      "and identified. Go down to get out.");
    SetExits( ([ "down" : ZONE_START ]) );
}
int CanReceive(object ob){
    return ::CanReceive(ob);
}
