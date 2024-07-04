#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("battle axe");
    SetId(({"axe","battleaxe"}));
    SetAdjectives( ({ "huge","large","heavy","montrously","battle",
        "two handed" }) ); 
    SetShort("huge battle axe");
    SetLong(
      "A monstrously large and heavy battle axe coated in "
      "dried blood, bits, and strands hair attached to pieces "
      "of scalp from its past victims."
    );
    SetMass(1000);
    SetHands(2);
    SetBaseCost("silver", 3);
    SetVendorType(VT_WEAPON);
    SetClass(50);
    SetDamageType(BLADE|BLUNT);
    SetWeaponType("blade");
}

void init(){
    ::init();
}
