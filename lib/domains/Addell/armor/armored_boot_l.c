#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();

    SetKeyName("armored boot");
    SetAdjectives( ({"armored", "orc", "orcish", "protective"}) );
    SetId(({"boot","left boot"}));
    SetShort("armored boot");
    SetLong(
      "An armored boot of orcish design. It is designed to "
      "cover the left foot and leg. It looks poorly designed "
      "and hastly contructed.");
    SetMass(60);
    SetBaseCost("copper", 40);
    SetProtection(BLUNT,15);
    SetProtection(BLADE,15);
    SetProtection(KNIFE,15);
    SetArmorType(A_LONG_BOOT);
    SetRestrictLimbs(({"left foot","left leg"}));
}

void init(){
    ::init();
}

