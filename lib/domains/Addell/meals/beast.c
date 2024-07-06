#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
    meal::create();

    SetKeyName("roast beast");
    SetId( ({ "meat","beast","roast","hunk"}) );
    SetAdjectives( ({ "savory","hunk of","spiced","delicious"}) );
    SetShort("hunk of roast beast");
    SetLong(
      "Savory and spiced, this hunk of meat looks delicious. "
      "The aroma of the cooked meat is like none you "
      "experienced before."
    );
    SetNoCondition(1);
    SetMass(50);
    SetStrength(15);
    SetBaseCost("copper", 20);
    SetMealType(MEAL_FOOD);
    SetMealMessages(
      "You eat your meat with no care what manner "
      "of beast it came from.",
      "$N eats $P hunk of roast beast not caring about "
      "the saliva dribbling down $P chin.");
}

void init(){
    ::init();
}
