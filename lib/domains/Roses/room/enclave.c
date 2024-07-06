//	Elohim Feb 2010
//  	ROOM TEMPLATE for the city of Roses

#include <lib.h>
#include <daemons.h>
#include "../areadefs.h"

inherit MROOM;

int enterHall();
int findClassMaster();

static void create() {
    ::create();

    SetClimate("indoors");	
    SetShort("Privately Managed Library");
    SetLong(
      "You are inside a refectory repurposed to serve as a library. "
      "Here volumes of text and artifacts are collected and "
      "examined closely by students and masters of sciences "
      "and natural understanding. Bookcases line the wall "
      "surrounding artifacts displayed in cases and large studies "
      "neatly arranged in pairs."	
    );
    SetItems( ([
        ({"refectory","library"}) : "",
        "text" : "",
        "artifacts" : "",
        "cases" : "",
        "case" : "",
        "bookcases" : "",
        "wall" : "",
        ({"large studies","studies"}) : "",
        ({"large study","study"}) : ""
      ]) );
    SetExits(([  
        "out" : MY_ROOM "/parade_e3",
        "up" : MY_ROOM "/arsportalis"
      ]));
    AddExit("west", MY_ROOM "/classhall_mage",(:enterHall:));
    findClassMaster();
}

void init() {
    ::init();
}

void reset() {
    ::reset();

    findClassMaster();
}


int findClassMaster(){

    object cm = find_living("johanai the adept");
    object here = load_object(MY_ROOM "/enclave");

    if(!present("johanai the adept")){

        if(!cm || !environment(cm)) 
            cm = new(MY_NPC "/class_master_mage");
        if(environment(cm) && environment(cm) != here)
            message("say",
              cm->GetName()+" vanishes in a ball of light.",
              environment(cm));

        cm->eventMove(here);

        message("say", cm->GetName()+" appears from a burst of lights.", 
          here);

        return 1;
    }

    return 0;
}

int enterHall() {

    object tp = this_player();

    if(tp->query_class() != "mage") {
        write("A force field glows brightly as it tries to "
          "deny your passage.");
        say(tp->GetName()+" pushes past a forcefield and "
          "enters the esoterium.", tp);

        return 1;
    }

    return 1;
}
