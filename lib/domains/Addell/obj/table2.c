#include <lib.h>

inherit LIB_TABLE;


void create() {
    ::create();

    SetKeyName("wooden table");
    SetId( ({ "table" }) );
    SetAdjectives( ({ "wood","wooden", 
        "simple", "warped", "stained" }) );
    SetShort("wooden table");
    SetLong("A simple wood table, warped and stained.");
    SetInventory(([
      ]));
    SetMass(274);
    SetBaseCost("silver",1 + random(3));
    SetMaxCarry(500);
}

void init(){
    ::init();
}

