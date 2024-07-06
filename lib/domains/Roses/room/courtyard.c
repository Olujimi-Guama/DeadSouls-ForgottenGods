#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int enterHall();
int findClassMaster();

static void create() {
    ::create();


    SetShort("Courtyard of the Broken Saints");
    SetLong(
      "The courtyard is used to house the shrines "
      "of different religions and cults. Here monks "
      "come from miles away to meditate and pay "
      "homage to thier ancestors. They sit and pray "
      "for days and teach the ways of the warrior "
      "priests to all those with an interest in thier "
      "spartan lifestyle. An enclosed hall to the "
      "west serves as a meeting place for monks of "
      "different disciplines and theologies."
    );
    SetItems( ([
        "courtyard" : "You're standing in it.",
        "shrines" : "Shrines dedicated to different dieties.",
        ({"diety","dieties"}) : "These all have thier own "
        "dedicated shrines.",
        ({"monk","monks"}) : "Monks of all orders and "
        "beliefs are welcomed to attend and participate.",
        ({"enclosed hall", "hall", "meeting place","west"}) : 
        "The enlcosed hall serves as a meeting place for "
        "monks.",
        //	Sounds from SetListen()
        ({"prayers","chanting","chants","individuals", 
          "prayer","chant","individual"}) : "You don't "
        "see that here."
      ]) );
    SetExits(([
        "east" : MY_ROOM "/monastery"        
      ]));
    AddExit("west", 
      MY_ROOM "/classhall_monk",(:enterHall:));
    SetListen( ([
        "default" : "Prayers, chanting, and moans of pain "
        "can be heard nearby.",
        "prayers" : "You listen closely to the prayers but "
        "they are not familiar to you. Heathen.",
        ({"chanting","chants","individuals"}) : "Individuals "
        "unknown are reciting an incantation in unison.",
        ({"prayer","chant","individual"}) : "Your ears are "
        "not trained well enough to pull that off."
      ]) );

    findClassMaster();
}

void init(){
    ::init();

    findClassMaster();	

}

int findClassMaster(){

    object cm = find_living("master huan");
    object here = load_object(MY_ROOM "/courtyard");

    if(!present("master huan")){

        if(!cm || !environment(cm)) 
            cm = new(MY_NPC "/class_master_monk");
        if(environment(cm) && environment(cm) != here)
            message("say",
              cm->GetName()+" vanishes in a pillar of "
              "pure fire.",
              environment(cm));

        cm->eventMove(here);

        message("say", cm->GetName()+" arrives from "
          "within a pillar of fire.", 
          here);

        return 1;
    }

    return 0;
}

int enterHall() {

    object tp = this_player();

    if(tp->query_class() != "monk") {
        write("A force field glows brightly as it tries to "
          "deny your passage.");
        say(tp->GetName()+" pushes past a forcefield and "
          "enters the sacred hall.", tp);

        return 1;
    }

    return 1;
}
