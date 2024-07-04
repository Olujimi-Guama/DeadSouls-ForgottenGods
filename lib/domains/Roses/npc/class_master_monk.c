/*   /////////////////////////////////////////
 *	From the Dead Souls Mud Library 
 *    An example class leader
 *    original created by Elohim@ForgottenGods *    
 */   /////////////////////////////////////////

#include <lib.h>

inherit LIB_LEADER;

int CheckVisitor();

static void create() {
    leader::create();

    SetKeyName("Master Huan");
    SetId("huan", "leader", "monk");
    SetShort("Master Huan, Retainer of the Sacred Flame");
    SetLong(
      "Before you is a man covered in a laymans orange robe. "
      "His wild beard frames a face that expresses endless "
      "experience and wisdom. His deep blue eyes reflect the "
      "calmness of his soul."
    );
    SetRace("nuar");
    SetClass("monk");
    SetLevel(45);
    SetGender("male");
    SetMorality(400);
    SetProperty("no bump", 1);
    SetGuard("west", (: CheckVisitor :));
    SetLanguage("Common", 100);
    SetDefaultLanguage("Common");
}


int AllowPass(object who, object what){

    if(who->GetClass() == GetClass()) return 1;

    if(wizardp(who)){
        write(GetName()+" is oblivious to your presence.");	
        return 1;
    }

    return ::AllowPass(who, what);
}

int CheckVisitor(object who){

    eventForce("shake");
    eventForce("say Sorry friend, only those of the order "
      "are allowed to pass.");

    return 0;
}
