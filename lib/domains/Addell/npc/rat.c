#include <lib.h>
#include "../areadefs.h"

inherit LIB_SENTIENT;


static void create() {
    sentient::create();

    SetKeyName("cave rat");
    SetAdjectives( ({"ratlike","unusual","large",
        "very","dangerous","dangerous looking","rat like"}) );
    SetId( ({"rat","rous","beast"}) );
    SetShort("a rodent of unusual size");
    SetLong("A very large, very dangerous-looking ratlike beast.");
    SetRace("rodent");
    SetGender("male");
    SetClass("fighter");
    SetLevel(1);
    SetMelee(1);
    SetMaxClones(5);
    SetMessage("come","$N scurries in.");
    SetMessage("leave","$N scurries $D.");    
    SetWanderSpeed(10);
}

void init(){
    ::init();
}

