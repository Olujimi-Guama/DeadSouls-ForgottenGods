#include <lib.h>

inherit LIB_ITEM;


static void create() {
    item::create();

    SetKeyName("key");
    SetId( ({ "key", "chest_key_jucrE7te" }) );
    SetAdjectives( ({ "metal","small" }) );
    SetShort("metal key");
    SetLong("It is a small key made of metal. The head has a clover design.");
    SetMass(10);
    SetBaseCost("copper", 1);
    SetDisableChance(100);
}

void init(){
    ::init();
}

