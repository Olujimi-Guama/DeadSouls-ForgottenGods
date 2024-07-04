
/*    /domains/Ylsrim/fish/shark.c
 *    from the Dead Souls Mud Library
 *    created by Descartes of Borg 960302
 *	modified by Elo'him@ForgottenGods 20110707
 */

#include <lib.h>
#include <meal_types.h>
#include <dirs.h>
#include <damage_types.h>
#include "../../areadefs.h"

inherit LIB_FISH;

void BiteMe(object who);
void newFish();

static void create() {
    fish::create();

    SetKeyName("Generic Beginners Rare Fish");
    SetId("Generic Beginners Rare Fish");
    SetShort( "fish");
    SetLong( "Generic Beginners Rare Fish" );
    SetMealType(MEAL_FOOD);
    SetMass(100); 
    SetStrength(50);
    SetBaseCost("silver", 10);
    SetFight(40);
    SetFood(MY_FISH "/fish_beginner_rare");

    if(clonep(this_object())) newFish();
}
int eventCatch(object who, object pole) { 
    call_out((: BiteMe, who :), 0);
    return 1;
}
void BiteMe(object who) {
    who->eventPrint("The rare fish bites you before it dies!");
    environment(who)->eventPrint("The rare fish bites " + who->GetName() +
      " before it dies!", who);
    who->eventReceiveDamage(this_object(), BITE, random(30), 0,
      who->GetRandomLimb("right hand"));
}


void init(){
    ::init();
}


void newFish(){

    string *fnames = ({"goatfish","snapdragon"});
    string *fdescs =({
      "It is an agressive sprecies of large fish with "
      "whiskers and dwarf horns.",
      "A large meaty fish that is recognized for it's "
      "unual membrane around it's mouth."});
    int i = random(sizeof(fnames));


    SetKeyName( fnames[i] );
    SetId( ({ fnames[i], "fish" }) );
    SetShort( fnames[i] );
    SetLong( fdescs[i] );

    return;
}
