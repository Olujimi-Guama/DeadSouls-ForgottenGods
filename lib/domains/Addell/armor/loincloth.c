#include <lib.h>
#include <size_types.h>
#include <armor_types.h>
#include <damage_types.h>
#include "../areadefs.h"

inherit LIB_WORN_STORAGE;


static void create() {
    ::create();

    SetKeyName("loincloth");
    SetId(({"cloth"}));
    SetAdjectives(({"loin","filthy"}));
    SetShort("filthy loincloth");
    SetLong(
      "This is a very large ragged cloth used to protect "
      "decency more than the body itself. Pockets have "
      "been sewn into it to provide some small means of "
      "storage."
    );
    SetMass(100);
    SetCanClose(0);
    SetClosed(0);
    SetMaxCarry(100);
    SetArmorType(A_PANTS);
    SetSmell( ([
        "default" : "P.U.",
      ]) );
    SetMoney( ([
        "platinum" : random(5)+1,
      ]) );
    SetInventory(([
        OBJ+ "vial_orange" : 1,
        OBJ+ "cavetroll_key" : 1,
      ]));
    SetSize(S_LARGE);
}

void init(){
    ::init();
}
