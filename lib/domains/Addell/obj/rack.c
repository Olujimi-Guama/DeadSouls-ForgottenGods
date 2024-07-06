#include <lib.h>
#include "../areadefs.h"

inherit LIB_SURFACE;

object to;


void create() {
    ::create();

    SetKeyName("rack");
    SetId(({"rack"}));
    SetAdjectives(({"crude", "mug", "crude mug"}));
    SetShort("crude mug rack");
    SetLong("This is a crude rack with pegs for "
      "storing cups and mugs.");
    SetMass(274);
    SetBaseCost("silver", 1);
    SetMaxCarry(100);
    SetInventory(([
        OBJ+ "mug" : 2 + random(3),
        OBJ+ "stein" : random(1)
      ]));
SetCanClose(0);
}

mixed CanGet(object ob) { 
    return "Moving the rack would make it fall apart!";
}

int CanReceive(object ob) {
    if(!inherits(LIB_FLASK,ob)){
        write("This is a rack for drinking utensils only.");
        return 0;
    }

    else return 1;
}

void init(){
    ::init();
}
