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

    SetKeyName("Johanai the Adept");
    SetId("tim", "leader", "mentor", "mage");
    SetShort("Johanai the Adept");
    SetLong(
      "Faint white eyes pierce your soul with intesity. "
      "Behind the thick white beard a regal face looks "
      "back at you. His tall slender frame is robed in "
      "the finest linens you have seen in this city."
    );
    SetRace("vorskh");
    SetClass("mage");
    SetLevel(45);
    SetGender("male");
    SetMorality(0);
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
    eventForce("say Sorry friend, only those of the cabal "
      "are allowed to pass.");

    return 0;
}
