//	Elohim Feb 2010
//  	ROOM TEMPLATE for the cave domain

#include <lib.h>
#include "../areadefs.h"

inherit LIB_ROOM;

void create() {
    room::create();

    SetClimate("indoors");
    SetNightLight(15);
    SetDayLight(25);
    SetAmbientLight(5);
    SetTown("Addell Grottos");
    SetShort("A Dark Cave");
    SetLong("CAVE TEMPLATE ROOM");
    SetItems(([
        ({ "cave","rocks","floor","ground" }) : 
        "Nothing out of the ordinary.",
      ]));
    SetExits( ([
        //"west" : ROOM+ "",
        //"east" : ROOM+ "",
      ]) );
    SetInventory(([
      ]));
}

void init(){
    ::init();
}
