#include <lib.h>
#include "../areadefs.h"

inherit LIB_STORAGE;


void create() {
    ::create();

    SetKeyName("chest");
    SetAdjectives(({"wooden","heavy"}));
    SetId(({"chest"}));
    SetShort("wooden chest");
    SetLong(
      "This is a heavy wooden chest used to store items."
    );
    SetMaxCarry(9000);
    SetInventory(([
        OBJ+ "omni" : 1,
        OBJ+ "food_storage1_key" : 1,
        ARMOR+ "boobytrap_ring" : 1,
        ARMOR+ "necklace" : 1,
        ARMOR+ "pajamas" : 1,
      ]));
    SetMoney( ([
        "silver" : random(50)+100,
        "copper" : random(100)+200        
      ]) );
    SetMass(2000);
    SetBaseCost("silver", 10);
    SetCanClose(1);
    SetClosed(1);
    SetCanLock(1);
    SetLocked(1);
    SetKey("chest_key_jucrE7te");
    SetPreventGet("The chest does not budge.");
}

void init(){
    ::init();
}
