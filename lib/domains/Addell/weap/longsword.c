#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;


int GetHands(){
    if(environment() && environment()->
      GetKeyName()=="war chief chiklis") return 1;
    else return 2;
}

static void create() {
    item::create();

    SetKeyName("longsword");
    SetId( ({ "sword","weapon" }) );
    SetAdjectives( ({ "long","well crafted",
        "bladed","two handed","blood-caked","blood caked" }) );
    SetShort("blood-caked longsword");
    SetLong(
      "A well crafted bladed weapon of exceptional lethality. "
      "It is well balanced for deep strokes. The previous owner "
      "cared little for maintenance; the luster of the sword "
      "all but gone because of the dried blood and gore "
      "coating the blade."
    );
    SetMass(500);
    SetHands(2);
    SetBaseCost("silver", 1);
    SetVendorType(VT_WEAPON);
    SetClass(25);
    SetDamageType(BLADE);
    SetWeaponType("blade");
}

void init(){
    ::init();
}
