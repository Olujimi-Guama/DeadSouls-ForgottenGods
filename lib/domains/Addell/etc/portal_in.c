/*  /verbs/spells/obj/portal.c
 *  created by Blitz@Dead Souls 960417
 *  used with the portal spell
 */

#include <lib.h>


inherit LIB_ITEM;

string targ = ZONE_START;


mixed direct_enter_obj(){
    return 1;
} 
mixed direct_enter_into_obj(){
    return direct_enter_obj();
}

string eventShowPortal() {
    object ob;
    string str;
    str = "A shimmering, magical portal that pulsates different "
    "shades of white and blue. ";

    ob = load_object(targ);

    if( !ob ) return "There are problems with this portal.";
    str += "Gazing into its fitful depths, you can barely see "
    "an occasional glimpse of " + ob->GetShort() + ".";
    return str;
}

mixed CanEnter(object who, string what) {
    if( !load_object(targ) ) return "The portal is non-functional.";
    else return 1;
}

int eventEnter(object who) {
    if( !who ) return 0;
    who->eventPrint("%^RED%^%^BOLD%^You step into the portal "
      "and feel reality shift around you.");
    who->eventMoveLiving(load_object(targ),
      "%^GREEN%^$N steps into the portal and disappears.",
      "%^GREEN%^$N steps out of a shimmering portal.");
    return 1;
}


static void create() {
    item::create();

    SetKeyName("portal");
    SetId("portal");
    SetAdjectives("pulsating", "shimmering");
    SetShort("%^YELLOW%^a shimmering portal%^RESET%^");
    SetLong((: eventShowPortal :));
    SetPreventGet("The portal is pure magic and lacks substance.");
    SetPreventPut("The portal is pure magic and lacks substabce.");
    SetMass(0);
    SetValue(0);
}
