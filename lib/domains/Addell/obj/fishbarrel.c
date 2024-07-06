#include <lib.h>
#include "../areadefs.h"

inherit LIB_STORAGE;


void create() {
    ::create();

    SetKeyName("barrel");
    SetId( ({ "barrel" }) );
    SetAdjectives( ({ "simple","oak","oaken","wood","wooden" }) );
    SetShort("oak barrel");
    SetLong("It is a simple wooden barrel used for holding things.");
    SetMass(474);
    SetMaxCarry(500);
    SetInventory( ([
        MEALS+ "herring" : 10 + random(40),
      ]) );
}

void init(){
    ::init();
}
