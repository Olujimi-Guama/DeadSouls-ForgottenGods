
/*    /domains/Ylsrim/fish/shark.c
 *    from the Dead Souls Mud Library
 *    created by Descartes of Borg 960302
 *	modified by Elo'him@ForgottenGods 20110707
 */

#include <lib.h>
#include <meal_types.h>
#include <dirs.h>
#include "../../areadefs.h"

inherit LIB_FISH;


void newFish();

static void create() {
    fish::create();
    SetKeyName("herring");
    SetId( ({ "fish" }) );
    SetAdjectives( ({ "red","saltwater","salt water" }) );
    SetShort("a red herring");
    SetLong("It is saltwater fish, and red in color.");
    SetMealType(MEAL_FOOD);
    SetMass(10); 
    SetStrength(10); 
    SetBaseCost("silver", 2);
    SetFight(4);
    SetFood( MY_FISH "/fish_beginner_common.c");

    if(clonep(this_object())) newFish();
}


void init(){
    ::init();
}


void newFish(){
    //char is too big
    string *fnames = ({"pelatia","maidenfish","minnow"});
    string *fdescs =({
      "pelatia",
      "maidenfish",
      "minnow"
    });
    int i = random(sizeof(fnames));


    SetKeyName( fnames[i] );
    SetId( ({ fnames[i], "fish" }) );
    SetShort( fnames[i] );
    SetLong( fdescs[i] );

    return;
}


