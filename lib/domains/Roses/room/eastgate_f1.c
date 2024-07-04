//	Written by Elohim	Feb 2010
//	The idea behind this room is that the player
//	knows there's more rooms so hopefully
//	they'll have the gumption to find
//	alternate means of entry.


#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int checkRubble();


static void create() {

    ::create();

    SetClimate("indoors");
    SetShort("Inside Eastgate");
    SetLong(
      "There is a layer of dust over every surface in the gatehouse. "
      "Light trickles in from the outside highlighting motes of dust "
      "cascading from above. A staircase with a stone launch ascend "
      "upwards against the inside walls. " 
    );
    SetItems( ([
        ({"pieces","piece","wood","stone""rubble"}) : "Random "
        "pieces of wood and stone from the collasped tower.",
        ({"gatehouse","chamber"}) : "You look around. Yep, still "
        "here.",
        ({"climb","path"}) : "You look up the spiral steps leading "
        "towards the upper tower.",
        "paraport" : "You look up into the upper tower but can't "
        "make anything out. But you just know it has to be up "
        "there.",
        ({"upper tower","tower","shadows","shadow"}) : "You "
        "look up into the tower. The steps lost the long battle "
        "against time and no longer provide any access to the "
        "paraport.",
        ({"wooden steps","wooden step"}) : "You follow the steps "
        "from where they rise from the stone up into the tower. "
        "You notice that the higer steps are missing or deteriorated.",
        ({"stone steps","stone step"}) : "The steps start the "
        "climb up."
      ]) );
    SetExits(([
        "up" : MY_ROOM "/eastgate_steps"
      ]));
    AddExit("out", MY_ROOM "/wall_e1", (:checkRubble:) );
    SetSmell("A faint musky ordor seems to drift down from upstairs.");
    SetTouch("A sudden feeling tells you are not alone in this place.");
}


void init(){
    ::init();
}


int checkRubble(string dir){

    object rroom = find_object("/domains/Roses/room/wall_e1");
    object tp = this_player();	
    string tpcn = tp->GetCapName();	

    if(!rroom || !(rroom->queryRubble()) ){
        message( "say", "Rubble blocks your exit!\n", 
          tp );
        message( "say", tpcn+ "'s exit is blocked by rubble.\n", 
          environment(tp), tp );
        return 0;
    }

    else 	return 1;

}

