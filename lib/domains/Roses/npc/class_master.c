#include <lib.h>
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("class master");
    SetId(({"master", "class master"}));
    SetShort("a wise class master");
    SetLong("The class master is here to induct players into their chosen class.");
    SetRace("human");
    SetClass("cleric");
    SetLevel(50);
    SetGender("male");
    SetMorality(1000);
    SetAction(5, ({
        "!say I can induct you into a new class if you are ready.",
        "!say Just tell me which class you want to join."
    }));
}

void init() {
    npc::init();
    add_action("induct", "induct");
}

int induct(string str) {
    object player = this_player();

    if(!str) {
        eventForce("say You need to specify which class you want to join.");
        return 1;
    }

    if(player->GetClass() != "none") {
        eventForce("say You are already in a class.");
        return 1;
    }

    if(str == "warrior" || str == "mage" || str == "cleric" || str == "thief") {
        player->SetClass(str);
        eventForce("say Congratulations! You are now a " + str + ".");
        return 1;
    } else {
        eventForce("say I do not recognize that class. Please choose from warrior, mage, cleric, or thief.");
        return 1;
    }
}
