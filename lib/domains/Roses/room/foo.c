//	Elohim Feb 2010
//  	ROOM TEMPLATE for the city of Roses

#include <lib.h>
#include "../areadefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("artic");
    SetAmbientLight(30);	
    SetTown("Roses");
    SetShort("BLANK_ROOM");
    SetLong("THIS ROOM NEEDS ATTENTION");
    SetItems( (["template" : "That's what this is." ]) );
    //	SetInventory(([  MY_OBJ "/case" :1   ]));
    //	SetExits(([  "square" : MY_ROOM "/square" ]));

}

void init(){
    ::init();
}




