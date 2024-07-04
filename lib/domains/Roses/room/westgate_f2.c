#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int keepOut(object tp);

static void create() {
    
    ::create();
    
    SetClimate("indoors");
    SetShort("Top of West Gate Tower");
    SetLong(
      "You adjust your eyes to the near absolute darkness "
      "and make out a landing. This is where the crumbled "
      "stairs below would have begun their descent. To "
      "the east there is a framing around what appears to "
      "be a door."
    );    
    SetSmell("A stale smell lingers about.");
    SetTouch("A sudden feeling tells you are not alone in this place.");
    
    SetItems( ([
        ({"darkness", "absolute darkness"}) : "You strain your eyes "
        "and barely make out the stairs and what could be a door.",
        "landing" : "Although you can barely see a thing you do notice "
        "that, with the stairs being crumbled, the only way down is "
        "the hard way.",
        ({ "crumbled stairs","crumbled stair", "stairs", "stair"}) : 
        "The stairs are crumbled away.",
        ({"framing","frame", "east", "door"}) : 
        "What appears to be a doorway.",
        "doorway" : "Looks to be a way through to the east."
      ]) );
    
    SetExits(([
        "east" : MY_ROOM "/classhall_thief",
        "down" : MY_ROOM "/westgate_f1"
      ]));
}

void init(){
    ::init();
    
    //okay so I am paranoid thinking someone will find an exploit
    keepOut(this_player());   
    
}


int keepOut(object tp){
    
    
    if(wizardp(tp)){
        write("\nThe function \"keepOut()\" has been called but you are currently "
          "logged in as your wizard character. Please use your test character for "
          "debug purposes. \n~Elo.\n");
        return 1;
    }
    
    if(tp->GetClass() != "thief"){	
        
        message( "say",
          "\n%^YELLOW%^BOLD%^You hear a rustle in the shadows and before you can "
          "react you are pushed off the ledge!%^RESET%^\n",
          tp );
        message( "say",
          tp->GetCapName()+" is pushed off into the darkness by a shadowed figure!\n",
          environment(tp), tp );
        write();
        say("You hear a noise and realize the wall has mysteriously closed.\n");
        
        tp->eventMoveLiving(MY_ROOM "/westgate_f1", "down", tp->GetCapName()+
          " comes tumbling in.");
        
        message( "shout",
          "%^BLUE%^BOLD%^A sinister voice shouts, %^RESET%^\"Come sniffing around "
          "again you'll be stuck like a pig, "+tp->GetCapName()+"!\"\n",
          ({environment(tp), this_object()}) );
        
        return 0;
    }
    
    return 1;
}
