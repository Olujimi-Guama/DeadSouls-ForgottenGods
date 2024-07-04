#include <lib.h>

inherit LIB_MATCH;


static void create() {
    match::create();

    SetKeyName("match");
    SetId("match");
    SetAdjectives( ({ "wooden" }) );
    SetShort("wooden match");
    SetLong(
      "A wooden match that you could strike "
      "and guaranteed to light! Ever-Strike!"
    );
    SetRadiantLight(2);
    SetStrikeChance(100);
    SetMinHeat(10);
    SetFuelRequired(1);
    SetMaxFuel(10);
    SetFuelAmount(10);
    SetRefuelable(0);
    SetMass(5);
    SetBaseCost("copper", 1);
    SetBurntValue(1);
}

void init(){
    ::init();
}

