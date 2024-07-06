#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

void create() {
    ::create();
    SetAmbientLight(30);
    SetShort("Fake Square");
    SetLong("This is where the square would be.");
    SetExits( ([
        "south" : MY_ROOM "/merchant_s1",
        "east" : MY_ROOM "/parade_e1",
        "west" : MY_ROOM "/parade_w1",
      ]) );
}
void init(){
    ::init();
}
