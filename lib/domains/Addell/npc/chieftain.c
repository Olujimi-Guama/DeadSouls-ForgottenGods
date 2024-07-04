#include <lib.h>
#include "../areadefs.h"

inherit LIB_SENTIENT;

int CheckOrc(mixed val){
    if(!val) return 0;
    if(!objectp(val)) return 0;
    if(val->GetRace() == "orc" || 
      val->GetRace() == "rodent") return 0;
    else eventForce("growl at "+val->GetKeyName());
    message("room",
      "The War Chief says, \"Oh, what a costly mistake "
      "you made you pink  little worm.\"" ,
      environment() );
    return 1;
}

static void create() {
    ::create();

    SetKeyName("War Chief Chiklis");
    SetId(({"chiklis","orc","chieftain","chief","large"}));
    SetAdjectives(({"orc","armored","professional","chieftain"}));
    SetShort("War Chief Chiklis");
    SetLong(
      "This is a large orc, covered in ornate tattoos and "
      "markings of power and prestige. His powerful frame is "
      "clearly accustomed to physically establishing his "
      "authority. His mane is braided and faced covered in "
      "paint. This is the beast-man that has brought war to "
      "the outpost and responisble for the ongoing massacre."
    );
    SetProperty("no bump", 1);
    SetProperty("no steal", 1);
    SetInventory(([
        WEAP+ "longsword" : "wield longsword",
        WEAP+ "sword" : "wield short sword",
        ARMOR+ "platemail" : "wear platemail",
        ARMOR+ "orc_helmet" : "wear helmet",
        ARMOR+ "chainmail_collar" : "wear collar",
        ARMOR+ "armored_boot_l" : "wear left boot",
        ARMOR+ "armored_boot_r" : "wear right boot",
        ARMOR+ "armored_glove_r" : "wear right glove",
        ARMOR+ "armored_glove_l" : "wear left glove",
      ]));
    SetRace("orc");
    SetLevel(3);
    SetClass("fighter");
    SetGender("male");
    /*
    SetSkill("multi-weapon", 16);    
    SetSkill("blade attack", 24);    
    SetSkill("blunt defense", 16);  
    SetSkill("melee defense", 16);  
    SetSkill("projectile defense", 8);  
    SetSkill("knife defense", 8);    
    */
    SetAction(20, ({
        "The orc casually eats on a roasted human arm and "
        "tosses the bone on the floor.",
        "The war chief laughs and wipes his mouth with his "
        "arm",
        "The man-beast grabs a large pork shoulder from "
        "a pot and starts ripping the meat off the bone. "
        "You notice a hand with fingers missing before "
        "realizing your error."
      }));
    SetCombatAction(50, ({ 
        "!spit",
        "say You worthless worm!",
        "say The Uruk will reclaim the earth!"
      }) );
    SetEncounter(  (: CheckOrc :) );
    SetGuard(OBJ+ "chest1", "The orc blocks your theft.");
}

void init(){
    ::init();
}

int eventDie(){
    if(sizeof(GetWieldingLimbs())){
        eventForce("laugh");
        eventForce("speak enjoy your victory, swine!");
        eventForce("pull lever");
    }
    else {
        eventForce("spit");
        eventForce("speak you have no idea what you've done, fool!");
    }
    return ::eventDie();
}
