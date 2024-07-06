#include <lib.h>
#include "../areadefs.h"

inherit ETC+ "cave_orc";


static void create() {
    ::create();

    SetKeyName("Orcish Guard");
    SetId(({"orc","guard"}));
    SetAdjectives(({"orcish"}));
    SetShort("orcish guard");    
    SetLong(
      "You stumble upon what at first appears to be another "
      "person lost in the cave until it looks up at you and "
      "bares its fangs at you. Although built somewhat like a "
      "human "+sex+" you see something is grotesquely... "
      "inhuman about this creature. "
    );
    SetInventory(([
        WEAP+ "sword" : "wield sword",
        ARMOR+ "leather_armor" : "wear leather armor",
        ARMOR+ "orc_boot_l" : "wear left boot",
        ARMOR+ "orc_boot_r" : "wear right boot",
      ]));
    SetRace("orc");
    SetLevel(1);
    /*
    SetClass("fighter");
    SetSkill("blade attack", 20);
    SetSkill("projectile defense", 10);
    */
}

void init(){
    ::init();
}
