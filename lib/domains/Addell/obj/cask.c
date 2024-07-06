// Consolidated the SIX casks objects into one.
// 201112nd Elo

#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_FLASK;

int barrelRoller(){

    mapping DrinkTypes = 
    ([ MEAL_ALCOHOL : ({"grog", "root tea"}),
      MEAL_DRINK : ({"water", "shroom juice"}) ]);
    int indx = random( sizeof( keys(DrinkTypes) ));
    int draws = 50 + random(950);
    string ctgr = keys(DrinkTypes)[indx], type;
    indx = random(sizeof(DrinkTypes[ctgr]));
    type = DrinkTypes[ctgr][indx];

    SetMealType(ctgr);
    SetFlaskContents(type);
    SetFlaskUses(draws);
    SetMaxFlask(draws); 

    return 1;
}


void create(){
    ::create();

    SetKeyName("cask");
    SetId( ({"cask","keg"}) );
    SetAdjectives( ({"large","wooden","wood"}) );
    SetShort("wooden cask");
    SetLong("A large wooden cask for containing fluids.");
    SetMass(2000);
    SetBaseCost("silver", 3);
    SetVendorType(VT_TREASURE);
    SetStrength(5);    
    SetTapped(1);
    SetPreventGet("The cask is firmly attached to the floor.");

    barrelRoller();
}

void init(){
    ::init();
}

mixed CanDrink(object who, string what){
    return "This is a tapped "+GetKeyName()+". You fill something "+
    "with it, you don't drink directly from it, you barbarian.";
}


