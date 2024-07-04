#include <lib.h>
#include <damage_types.h>
#include <size_types.h>
#include "../areadefs.h"

inherit LIB_NPC;


static void create() {
    npc::create();

    SetKeyName("troll");
    SetId(({"cavetroll"}));
    SetAdjectives(({"dirty","cave"}));
    SetShort("cave troll");
    SetLong(
      "The dirty cavetroll is a huge and monstrously "
      "powerful creature with an even more vicious "
      "temperament. It had been trapped and imprisoned; "
      "fed offenders that angered its keepers. Because of "
      "its thick, rock-like hide it is difficult to injure. Its "
      "thick muscular build offers its victims little chance "
      "of survival."
    );
    SetInventory(([
        ARMOR+ "loincloth" : "wear loincloth",
      ]));
    SetLevel(2);
    SetRace("troll");
    SetClass("fighter");
    SetGender("male");
    SetMelee(1);
    /*
    SetSkill("melee attack",50,50,10);
    SetStat("strength",90,1);
    SetStat("agility",50,1);
    */
    SetResistance(BLADE,"high");
    SetResistance(KNIFE,"high");
    SetResistance(PIERCE,"high");
    SetResistance(BITE,"high");
    SetEncounter(100);
    SetSize(S_LARGE);
}

void init(){
    ::init();
}
