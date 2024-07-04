#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;


static void create() {
    item::create();

    SetKeyName("short sword");
    SetId( ({ "sword", "short sword" }) );
    SetAdjectives( ({ "short","shoddy" }) );
    SetShort("short sword");
    SetLong(
      "A shoddy sword  marred by visible impact "
      "and indentation. The edge has been serrated "
      "unintentionally from abuse and poor maintenance. "
      "It's hilt missing, the handle nothing more than dirty "
      "rags tied about with stains of dried blood and grime."
    );
    SetMass(300);
    SetBaseCost("copper", 60);
    SetVendorType(VT_WEAPON);
    SetClass(15);
    SetDamageType(BLADE);
    SetWeaponType("blade");
}

void init(){
    ::init();
}
