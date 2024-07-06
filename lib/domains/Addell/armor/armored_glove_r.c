#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();

    SetKeyName("armored glove");
    SetAdjectives( ({"armored", "orc", "orcish", "protective"}) );
    SetId(({"glove","right glove"}));
    SetShort("armored glove");
    SetLong(
      "An armored glove of orcish design. It is designed to "
      "cover the right hand and arm. It looks poorly "
      "designed and hastly contructed."
    );
    SetMass(60);
    SetBaseCost("copper", 30);
    SetProtection(BLUNT,15);
    SetProtection(BLADE,15);
    SetProtection(KNIFE,15);
    SetArmorType(A_LONG_GLOVE);
    SetFingers(6);
    SetRestrictLimbs(({"right hand","right arm"}));
}

void init(){
    ::init();
}

