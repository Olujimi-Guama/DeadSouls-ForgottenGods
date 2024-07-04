#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;


static void create(){
    armor::create();

    SetKeyName("uniform");
    SetAdjectives( ({"food workers","food worker's"}) );
    SetId( ({"dingy", "overalls", "burlap", "smock"}) );
    SetShort("burlap smock");
    SetLong(
      "A dingy burlap sack fitted to use as a smock. "
      "It meets the food service uniform specification "
      "of the Orc Food Handling guidelines."
    );
    SetMass(50);
    SetArmorType(A_BODY_ARMOR);
}

void init(){
    ::init();
}
