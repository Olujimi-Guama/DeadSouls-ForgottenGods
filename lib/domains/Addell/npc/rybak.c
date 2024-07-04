#include <lib.h>
#include <position.h>
#include "../areadefs.h"

inherit LIB_NPC;


static void create() {
    ::create();

    SetKeyName("Rybak the Orcish Cook");
    SetId( ({ "rybak","cook","orc" }) );
    SetAdjectives( ({ "orcish","cave" }) );
    SetShort("orcish cook");
    SetLong(
      "The disgusting beast-man is covered head to toe with "
      "layers of scars and scabs over its patchy skin. All its "
      "visible body and face is markings and patterns with no "
      "immediate known purpose. A large scar runs down from its "
      "forehead down to its chin from a wound that also must "
      "have claimed its now milky right eye. Its right ear is "
      "nothing more than a knob of scarred tissue; lost in some "
      "battle or dispute long ago."
    );
    SetRarity(3, 1);
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
    AddCurrency("copper", random(200));
    SetInventory(([
        ARMOR+ "foodsmock" : "wear smock",
        WEAP+ "cleaver" : "wield cleaver in right hand"
      ]));
    SetAction(5, ({
        "The cave orc works a lump of meat skillfully.",
        "The orc gives a strong chop at a piece of unidentified "
        "meat on the chopping block cleaving through bone and sinew.",
        "The man-beast lifts a human corpse up and onto "
        "a waiting meat hook.",
        "The cook smashes a roach with the flat of his cleaver "
        "and wipes it off on his bloody smock.",
        "The cave orc absently scratches at the "
        "scar down his ruined eye."
      }));
    SetCombatAction(50, ({ 
        "emote howls in anger!",
        "say Tonight we feast on the long pig, lads!",
        "emote blocks the attack with the flat "
        "of his cleaver and readies for his next strike."
      }) );
}

void init(){
    ::init();
}
