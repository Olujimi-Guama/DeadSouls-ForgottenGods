#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_FLASK;


void create(){
    ::create();

    SetKeyName("lister bag");
    SetId( ({"lister","bag","tripod"}) );
    SetAdjectives( ({"large","canvas",
        "wood","suspended"}) );
    SetShort("lister bag");
    SetLong(
      "A large canvas bag suspended on a tripod containing "
      "drinking water."
    );
    SetMass(2000);
    SetVendorType(VT_TREASURE);
    SetStrength(5);
    SetMaxFlask(1000); 
    SetFlaskUses(1000);
    SetFlaskContents("water");
    SetMealType(MEAL_DRINK);
    SetTapped(1);
    SetPreventGet("Each time it is moved the water sloshes "
      "about. You decide to let it be.");
}

void init(){
    ::init();
}

mixed CanDrink(object who, string what){
    return "This is a "+GetKeyName()+". You fill something "
    "with it, you don't drink directly from it, you barbarian.";
}

