#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("sharp dagger");
    SetId( ({ "dagger"}));
    SetAdjectives( ({ "sharp","fine","wicked","wicked-looking"}));
    SetShort("wicked dagger");
    SetLong(
      "A sharp, wicked dagger. It is nothing much than rotted "
      "leather wrapped abound the base of a sharpened "
      "shard of metal."
    );
    SetMass(150);
    SetBaseCost("copper", 8);
    SetVendorType(VT_WEAPON);
    SetClass(10);
    SetDamageType(KNIFE);
    SetWeaponType("knife");
}
void init(){
    ::init();
}
