#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("sharp axe");
    SetId( ({ "axe"}));
    SetAdjectives( ({ "sharp","small","hand"}));
    SetShort("hand axe");
    SetLong(
      "The head of this small, sharp handaxe is made from "
      "stone. The intimidating edge was chipped to a mean "
      "sharpness. Not a lot of work went into the handle. "
      "This is evident by the twisted wood and the leather "
      "cords attaching the head."
    );
    SetMass(150);
    SetBaseCost("copper", 40);
    SetVendorType(VT_WEAPON);
    SetClass(20);
    SetDamageType(BLADE|BLUNT);
    SetWeaponType("blade");
}
