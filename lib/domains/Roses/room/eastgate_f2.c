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
    SetShort("Top of East Gate Tower");
    SetLong(
      "The top of the east tower is cleared of debris and rubbish "
      "that occupies the lower floors. There is evidence of traffic "
      "leading into the west chamber and down the stairs below. "
      "Laterns are hung on iron rings that burn brightly, illuminating "
      "the way."
    );
    SetItems( ([
        "east tower" : "The east tower stands aside the city gate.",
        "tower" : "There is the east tower, in which you are now in.",
        ({"city gate","gate"}) : "You cannot see that from here.",
        ({"debris","rubbish"}) : "You strangely see none here.",
        "here" : "Look at what?",
        "lower floors" : "There must be a section past the stairs.",
        "lower floor" : "You cannot see past the stairs.",
        "floors" : "You stare at the floor discoving nothing.",
        "floor" : "Like an idiot you stare at the floor.",
        "evidence" : "You see the floor is clear of rubble.",
        "west chamber" : "It is too far and hazy to examine "
        "behind the blue forcefield.",
        ({"blue forcefield","forcefield","west"}) : "A forcefield to "
        "the west crackles as if weakening.",
        "stairs" : "The stairs descend to the lower floors below.",
        "laterns" : "Two laterns on each side of the doorway hang "
        "from iron rings.",
        "latern" : "This latern hangs from a latern ring much like "
        "its counterpart.",
        ({"counterpart","other"}) : "It's just like the other.",
        "doorway" : "There is a forcefield restricting access.",
        "iron rings" : "Two rings hang from the wall to rest laterns upon.",
        "iron ring" : "It hangs from the wall just like its counterpart.",
        "ring" : "Do you mean the iron ring?"
      ]) );
    SetExits(([  
        "down" : MY_ROOM "/eastgate_steps",
      ]));
    AddExit("west", MY_ROOM "/classhall_thief",(:enterHall:));

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

    object cm = find_living("master thief reichsacht");
    object here = load_object(MY_ROOM "/eastgate_f2");

    if(!present("master thief reichsacht")){

        if(!cm || !environment(cm)) 
            cm = new(MY_NPC "/class_master_thief");
        if(environment(cm) && environment(cm) != here)
            message("say",
              cm->GetName()+" fades into the shadows.",
              environment(cm));

        cm->eventMove(here);

        message("say", cm->GetName()+" appears from the shadows.", 
          here);

        return 1;
    }

    return 0;
}

int enterHall() {

    object tp = this_player();

    if(tp->query_class() != "thief") {
        write("A force field glows brightly as it tries to "
          "deny your passage.");
        say(tp->GetName()+" pushes past a forcefield and "
          "enters the hideout.", tp);

        return 1;
    }

    return 1;
}
