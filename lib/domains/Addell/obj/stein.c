#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_FLASK;


void create(){
    ::create();

    SetKeyName("grog stein");
    SetId( ({"stein", "mug"}) );
    SetAdjectives( ({"grog","fancy"}) );
    SetShort("stein");
    SetLong(
      "A large mug for holding vast quantity of grog. It is  "
      "bone-like material fashioned in a very artistic way "
      "and no doubt valued beyond its utility usage."
    );
    SetMass(30);
    SetBaseCost("gold", 1);
    SetVendorType(VT_TREASURE);
    SetFlaskUses(0);
    SetStrength(5);
    SetMaxFlask(10); 
    SetMealType(MEAL_DRINK);
}

void init(){
    ::init();
}
