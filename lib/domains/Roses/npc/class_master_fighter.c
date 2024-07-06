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

    SetKeyName("Pilus Chenosa");
    SetId("chenosha", "leader", "mentor", "fighter");
    SetShort("Pilus Chenosha Vis et Virtus");
    SetLong(
      "Chenosa is the Pilus of Roses serving the "
      "Jeweled Cities' Legionnaire. She is clad in "
      "leather armor, a custom of the Legionnaire "
      "during peacetime. As tall as she is serious, "
      "her scowl and shaven head only accentuates "
      "her savage beauty."
    );
    SetRace("nuar");
    SetClass("fighter");
    SetLevel(45);
    SetGender("female");
    SetMorality(0);
    SetProperty("no bump", 1);
    SetGuard("down", (: CheckVisitor :));
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
    eventForce("say Sorry friend, only those of the legion "
      "are allowed to pass.");

    return 0;
}
