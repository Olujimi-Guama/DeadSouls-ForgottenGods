#include <lib.h>
#include <vendor_types.h>
#include "../areadefs.h"

inherit LIB_NPC;


static void create() {
    ::create();

    SetKeyName("Gorm the Orcish Plunderer");
    SetId(({"gorm","orc","plunderer","brute","man-beast"}));
    SetAdjectives(({"orchish","dirty"}));
    SetShort("orchish plunderer");
    SetLong(
      "You can see the thick tendons in the neck of "
      "the dirty brute work as it looks around. You "
      "get a deep feeling that whatever it is doing it "
      "doesn't want witnesses and better to stay clear."
    );
    SetRarity(3, 2);
    SetProperty("no bump", 1);
    SetProperty("no steal", 1);
    SetRace("orc");
    SetLanguage("Tangetto", 100);
    SetDefaultLanguage("Tangetto");
    SetGender("male");
    SetClass("fighter");
    SetLevel(2);
    SetMelee(1);
    /*
    SetSkill("blade", 2);
    */
    AddCurrency("copper", 10 + random(90));
    SetInventory(([
        WEAP+ "axe" : "wield axe in left hand.",
        OBJ+ "chest_small" : 1
      ]));    
    SetAction(20, ({
        "The orc bites into a coin and nods "
        "in approval before placing it into his purse.",
        "The man-beast grunts after biting a coin "
        "and tosses it away.",
        "The plunderer looks over some recently "
        "procured items and releases a sinister chuckle."
      }));
    SetCombatAction(50, ({ 
        "!spit",
        "say You worthless worm!",
        "say Let's see if Rybak has space in his pot for you!"
      }) );
}

void init(){
    ::init();
}
