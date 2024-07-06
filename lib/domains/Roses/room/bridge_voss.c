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
    SetShort("Voss Bridge");
    SetLong("THIS ROOM IS JUST HERE WHILE "
      "CONTENT IS BEING WRITTEN. IT IS NOT "
      "A GODDAMN BUG DON'T REPORT IT.");
    SetItems( (["template" : "That's what this is." ]) );
    //	SetInventory(([  MY_OBJ "/case" :1   ]));
    SetExits(([
		"east" : MY_ROOM "/beggars_2",
		"west" : MY_ROOM "/monastery"
	]));
    
}

void init(){
    ::init();
}




