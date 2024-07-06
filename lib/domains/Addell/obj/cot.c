#include <lib.h>
#include <props.h>

inherit LIB_BED;


static void create() {
    ::create();

    SetKeyName("cot");
    SetId( ({ "cot","bed" }) );
    SetAdjectives( ({ "simple","dilapidated"}) );
    SetShort("simple cot");
    SetLong(
      "A dilapidated cot made from scrap materials."
    );
    SetMass(500);
    SetBaseCost("copper", 15);
    SetMaxSitters(2);
    SetMaxLiers(1);
}

void init(){
    ::init();
}
