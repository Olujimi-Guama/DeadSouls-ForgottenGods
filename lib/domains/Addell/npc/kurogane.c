#include <lib.h>
#include <vendor_types.h>
#include "../areadefs.h"

inherit LIB_NPC;

int knifeThrow(){

    object targ;
    object proj = present("dagger",this_object());
    object *targs = filter(get_livings(environment()), 
      (: member_array($1, GetEnemies()) != -1 :) );

    if(sizeof(targs)){ 

        targ = targs[random(sizeof(targs)-1)];

        if(!proj)proj = new(WEAP+ "knife");
        proj->eventMove(this_object());

        tell_room(environment(), "\n%^BLUE%^BOLD%^"
          "Kurogane plucks a dagger from thin air!"
          "%^RESET%^");
        tell_room(environment(), "War-Consulate Kurogane "
          "exclaims in Common,\"%^CYAN%^BOLD%^"
          "You thought us too savage for magics?! "
          "Die!!!\"%^RESET%^\n");

        eventForce("throw dagger at "+targ->GetKeyName());
    }

    return 1;
}


static void create() {
    ::create();

    SetKeyName("War-Consulate Kurogane");
    SetId(({"kurogane","orc","plunderer","brute","man-beast"}));
    SetAdjectives(({"War-Consulate Kurogane","dirty"}));
    SetShort("War-Consulate Kurogane");
    SetLong(
      "Before you stands a distinguished orc that looks much "
      "more civilised than his other bethren encountered. He "
      "surrounds himself with the finer goods pillaged from the "
      "human outpost raids. Standing tall he nears your height "
      "with an intimidating build and pencahnt for flair."
    );
    SetProperty("no bump", 1);
    SetProperty("no steal", 1);
    SetRace("orc");
    SetLanguage("Tangetto", 100);
    SetDefaultLanguage("Tangetto");
    SetGender("male");
    SetClass("fighter");
    SetLevel(2);
    /*
    SetSkill("blade", 3);
    SetSkill("projectile", 2);
    */
    AddCurrency("copper", 10 + random(90));
    SetInventory(([
        WEAP+ "longsword" : "wield sword",
        ARMOR+ "chainmail" : "wear chainmail",
        ARMOR+ "orc_tallboot_l" : "wear left boot",
        ARMOR+ "orc_tallboot_r" : "wear right boot",
        OBJ+ "key_chest1" : 1
      ]));    
    SetAction(2, ({
        "The orc examines some documents.",
        "Kurogane grunts after studying a large drawing on the wall.",
        "The orc scratches at its chin.",
        "The War-Consulate catches a spinning dagger in the air. "
        "You are left puzzled wondering where it fell from.",
        "Kurogane tosses a dagger into the air. The gleam it "
        "produces while spinning momentarily blinds you."
      }));
    SetCombatAction(1, ({
        (: knifeThrow :),
        "emote spins his sword around his back with a dazzling "
        "display and readies for another thrust.",
        "say I will take your ass and laugh at "
        "your wimpering through the night!"
      }) );
    SetGuard("south","The commander bars your way!");
}

void init(){
    ::init();
}
