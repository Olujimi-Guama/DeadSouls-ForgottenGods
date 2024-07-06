#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;


static void create(){
    armor::create();

    SetKeyName("dress");
    SetId(({"dress"}));
    SetAdjectives(({"improvised","ragged"}));
    SetShort("ragged dress");
    SetLong(
      "A ragged dress made apparently from scraps of "
      "materials and of improvised design. It is soiled "
      "and greasy with mis-matched rags of different "
      "colors and materials."
    );
    SetMass(10);
    SetBaseCost("copper", 10);
    SetArmorType(A_BODY_ARMOR);
}

void init(){
    ::init();
}
