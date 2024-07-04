#include <lib.h>
#include <meal_types.h>
#include <dirs.h>
#include "../areadefs.h"

inherit LIB_FISH;

static void create() {
    fish::create();

    SetKeyName("herring");
    SetId( ({ "fish" }) );
    SetAdjectives( ({ "pickled","red",
        "saltwater","salt water","bloated"}) );
    SetShort("a red herring");
    SetLong(
      "A saltwater fish, turned red and bloated by orcish pickling."
    );
    SetMealType(MEAL_FOOD);
    SetMass(10); 
    SetStrength(2); 
    SetBaseCost("copper", 5);
    SetFight(4);
    SetFood(MEALS+ "herring");
}

void init(){
    ::init();
}
