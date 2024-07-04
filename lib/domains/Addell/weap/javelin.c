#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("javelin");
    SetAdjectives( ({"throwing", "small", 
        "light","gnawed","wooden", "gnawed wooden"}) );
    SetId( ({"spear","javelin"}) );
    SetShort("gnawed wooden spear");
    SetLong(
      "This small wooden spear is gnawed and pocked from "
      "years of neglect. Its only practical function is to thow "
      "it at a target-- have it be an enemy or the bottom of "
      "a trash bin."
    );
    SetMass(50);
    SetVendorType(VT_WEAPON);
    SetClass(30);
    SetDamageType(PIERCE);
    SetWeaponType("projectile");
}

void init(){
    ::init();
}
