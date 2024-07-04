#include <lib.h>
#include "../areadefs.h"

inherit ETC+ "cave_orc";


int GetEnemyChaser() { return 1; }

mapping dressMe(){

    mapping loadout = ([
      ARMOR+ "orc_boot_l" : "wear left boot",
      ARMOR+ "orc_boot_r" : "wear right boot",
    ]);

    if(random(100) < 10){        
        loadout[WEAP+ "longsword"] = "wield sword";
        loadout[ARMOR+ "chainmail"] = "wear chainmail";
    }
    else{
        loadout[WEAP+ "axe"] = "wield axe in right hand";
        loadout[WEAP+ "sword"] = "wield sword in left hand";
        loadout[ARMOR+ "leather_armor"] = "wear leather armor";
    }

    return loadout;
}

static void create() {
    ::create();

    SetKeyName("Orcish Soldier");
    SetId(({"orc","soldier"}));
    SetAdjectives(({"orcish"}));
    SetShort("orcish soldier");
    SetLong(
      "You stumble upon what at first appears to be "
      "another person lost in the cave until it looks "
      "up at you and bares its fangs at you. "
      "It appears as a well armored and muscular "+
      (sex=="female"?"woman":"man")+" but... wrong. "
    );
    SetInventory( dressMe() );
    SetRace("orc");
    SetLevel(1);
    SetClass("fighter");
    SetSkill("blade attack", 30);
    SetSkill("blade defense", 10);
    SetWanderSpeed(10);
}

void init(){
    ::init();
}
