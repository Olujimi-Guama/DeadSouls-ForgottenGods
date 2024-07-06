//	Elohim Feb 2010
//	The idea behind this room is that the player
//	knows there's more rooms so hopefully
//	they'll have the gumption to find
//	alternate means of entry.


#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int keepTrying();


static void create() {

    ::create();

    SetClimate("indoors");

    SetShort("Inside Westgate");
    SetLong(
      "Rubble hinders your movement inside the gatehouse. "
      "There is little left since the final days this chamber found "
      "use due to hard times. Stone steps begin the path "
      "leading up to the paraport. Inside the upper tower the "
      "stone stairs begin the flight up before giving way to the "
      "wooden steps." 
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
        ({"wooden steps","wooden step","steps","step"}) : 
        "You follow the steps from where they rise from the "
        "stone up into the tower. You notice that the higer "
        "steps are missing or deteriorated.",
        ({"stone steps","stone step"}) : "The steps start the "
        "climb up."
      ]) );
    SetExits(([
        "out" : MY_ROOM "/wall_w1"
      ]));
    AddExit("up", MY_ROOM "/westgate_f2", (:keepTrying:) );
}


void init(){
    ::init();
}


int keepTrying(string dir){

    //	These are the variables to select a random message. 
    //	This keeps it fresh! Notice in the two string arrays they match. 
    //	Sizeof()  with random will always get the right interger 
    //	so it doesn't send any out of index errors.
    //	Turn <debug on> and uncomment to see a copy of message printed to room


    object tp = this_player();	
    string tpcn = tp->GetCapName();
    string *_tp = ({ 
      "You vault up and miss the steps by an embarrassing margin.",
      "You try to climb the wall and keep slipping to the ground.",
      "You stretch, jump, and cry but it gets you nowhere.",
      "You successfully climb the steps... and fall."
    });
    string *_env = ({ 
      tpcn+" vaults up and misses the steps by an embarrassing margin.",
      tpcn+" tries to climb the wall and keeps slipping to the ground.",
      tpcn+" stretches, jumps, and cries at his fail.",
      tpcn+" successfully climbs the steps... not really. \n"+tpcn+" fell."
    });

    int r = random(sizeof(_tp));	

    if(tp->GetClass() == "thief"){

        // only rogues get training

        if(tp->GetBaseSkillLevel("climbing") > 24 ){

            message( "say", "\nIn a display of agile dominance, you grapple "
              "and bounce your way up the wall.", tp );
            message( "say", "\nIn a display of agile dominance, "+tpcn+
              " leaps up the wall and out of sight.", environment(tp), tp );

            return 1;
        }

        if(random(100) < 60 ){
            message( "say", "\nYou climb the side of the wall slowly and "
              "pathetically until you manage to finally make it up.", tp );
            message( "say", "\n"+tpcn+" climbs the side of the wall slowly "
              "and pathetically until "+nominative(tp)+"manages to "
              "finally make it up.", environment(tp), tp );

            if(!tp->GetSkill()) tp->AddSkill("climbing", 3);

            tp->eventTrainSkill("climbing", random(100), 0, 1);

            return 1;
        }	
    }   

    message( "say", "\n"+_tp[r]+"\n", tp );
    message( "say", "\n"+_env[r]+"\n", environment(tp), tp );

    //debug("\nPrintENV: "+_env[r]+"\n");

    //	Yes, I'm an ass like that.
    //	since this generally a newbie area damage isnt dealt
    return 0;
}
