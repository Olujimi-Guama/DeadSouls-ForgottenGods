#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("sharp axe");
    SetId( ({ "cleaver","axe"}));
    SetAdjectives( ({ "butchers","small"}));
    SetShort("butcher's cleaver");
    SetLong(
      "You look upon a cleaver larger than any you've seen "
      "and twice as vile. The soft arch of the blade is interrupted "
      "by chips and notches from wear. Bits of gore and bone "
      "chips are dried to the body of the partially rotted wood "
      "handle."
    );
    SetMass(120);
    SetBaseCost("Silver", 1);
    SetVendorType(VT_WEAPON);
    SetClass(25);
    SetDamageType(BLADE);
    SetWeaponType("blade");
}

int eventStrike(object target) {

    if( random(100) > 10 ) return item::eventStrike(target);
    message("environment", 
      environment()->GetName()+" shouts, \"%^RED%^BOLD%^"
      "Ahhh, fresh meat!%^RESET%^\"",
      environment(target), environment());
    message("player", 
      "You shout, \"%^RED%^BOLD%^Ahhh, "
      "fresh meat!%^RESET%^\"",
      environment());
    return item::eventStrike(target) + random(50)+10;
}

void init(){
    ::init();
}
