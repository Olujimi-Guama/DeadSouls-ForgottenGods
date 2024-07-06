//	Elohim Feb 2010
//  ROOM TEMPLATE for the city of Roses

#include <lib.h>
#include "../areadefs.h"

inherit LIB_FISHING;

static void create() {
    fishing::create();
    
    SetClimate("artic");
    SetAmbientLight(30);	
    SetTown("Roses");
    SetShort("Reid River Bridge");
	SetCoordinates("0,-1,0");
    SetLong(
	"You approach a stone arched bridge that "
	"crosses the River Reid."
	);
    SetItems( (["template" : "That's what this is." ]) );
    //	SetInventory(([  MY_OBJ "/case" :1   ]));
    SetExits(([
        "north" : MY_ROOM "/_square",
        "south" : MY_ROOM "/merchant_s1"
      ]));
   SetChance(90); 
SetFish( ([
                MY_MEALS "/beginner" : 10,
                MY_MEALS "/beginner_rare" : 1,
                ]) );
	    }

void init(){
    ::init();
}