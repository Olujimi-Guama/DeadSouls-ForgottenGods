#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_FLASK;


void create(){
    ::create();

    SetKeyName("mug");
    SetId( ({"mug", "mug made of clay"}) );
    SetAdjectives( ({"poorly crafted","crafted","clay"}) );
    SetShort("clay mug");
    SetLong("A poorly crafted mug made of clay");
    SetMass(5);
    SetBaseCost("copper", 3);
    SetVendorType(VT_TREASURE);
    SetFlaskUses(0);
    SetStrength(5);
    SetMaxFlask(2); 
    SetMealType(MEAL_DRINK);    
}

void init(){
    ::init();
}

