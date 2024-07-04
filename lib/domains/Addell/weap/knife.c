#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;


int timer;

int knifeGoPoof(){

    object owner;

    if(environment()){

        owner = environment();

        if(this_object()->GetWielded())
            this_object()->eventUnequip(owner);
    }

    message( "my_action",
      "%^BOLD%^The knife shimmers then vanishes!%^RESET%^",
      owner);

    if(owner->is_living()){

        message( "other_action", "%^WHITE%^"+
          owner->GetName()+" jumps in surprise at a "
          "shimmering light emitted from something "+
          nominative(owner)+" was carrying.%^RESET%^",
          environment(owner), owner);		

        this_object()->eventDestruct();	
    }
    return 1;
}


static void create() {
    item::create();
    SetKeyName("pristine throwing knife");
    SetId( ({ "knife","throwing knife"}));
    SetAdjectives( ({ "pristine","throwing"}));
    SetShort("pristine throwing knife");
    SetLong(
      "A pristine throwing knife. It has no markings "
      "or any indication it was crafted by mortal hands. "
      "it's gleaming like a killer's smile."
    );
    SetMass(10);
    SetValue(0);
    SetClass(10);
    SetDamageType(KNIFE|PIERCE);
    SetWeaponType("projectile");
}
void init(){
    ::init();

    if(clonep() && environment() && !timer &&
      environment()->GetKeyName()!="war-consulate kurogane"){
        call_out("knifeGoPoof", 10);
        timer = 1;
    }
}
