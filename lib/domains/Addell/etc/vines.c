#include <lib.h>
#include <climb.h> // defines CLIMB_UP
#include "../areadefs.h"

inherit LIB_DUMMY; // These do not show up in desc, but you can look at them
inherit LIB_CLIMB; // This makes it climbable

int ClimbUp();

static void create() {
    dummy::create();

    SetKeyName("vine");
    SetId("vines","vines");
    SetAdjectives("adobe", "bank");
    SetShort("wild vines");
    SetLong("The wild vines seem sturdy enough to climb.");
    SetClimb( (: ClimbUp :), 1);
}


int ClimbUp(){

    string omsg,imsg,dest;
    object who, lever;     

    dest=ROOM+  "chieftain";
    who=this_player();
    omsg = "$N climbs up "+GetDefiniteShort()+".";
    imsg = "$N comes climbing in.";

    if( !(lever = present( "lever", 
          load_object(ROOM+ "chieftain")))->
      GetSprung() ){

        write("You fumble at a switch overhead.");
        say("You hear scratching down below.");
        lever->openDoor(who);
    }		

    who->eventMoveLiving(dest, omsg, imsg);
}

mixed CanGet(object ob) { 
    return "You come to realize that gardening is "
    "not your top priority at this particular moment.";
}
