#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;

static void create(){
    armor::create();

    SetKeyName("gold necklace");
    SetId(({"necklace"}));
    SetAdjectives( ({"gold","golden","beautiful"}) );
    SetShort("golden necklace");
    SetLong("This is a simple and beautiful gold necklace."); 
    SetMass(1);
    SetDollarCost(400);
    SetArmorType(A_COLLAR);
}

void init(){
    ::init();
}
