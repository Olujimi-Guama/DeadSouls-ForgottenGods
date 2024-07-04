#include <lib.h>
#include "../areadefs.h"

inherit LIB_STORAGE;


void create() {
    ::create();

    SetKeyName("chest");
    SetAdjectives(({"wooden","heavy"}));
    SetId(({"chest"}));
    SetShort("a wooden chest");
    SetLong("This is a heavy wooden chest used to store items.");
    SetInventory(([
        OBJ+ "letter1" : 1,
        OBJ+ "letter2" : 1,
      ]));
    SetMoney( ([
        "copper" : random(50)+100        
      ]) );
    SetMass(2000);
    SetBaseCost("silver", 10);
    SetMaxCarry(500);
    SetCanClose(1);
    SetClosed(1);
}

void init(){
    ::init();
}
