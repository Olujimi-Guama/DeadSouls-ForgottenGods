#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int enterHall();
int findClassMaster();

static void create() {
    ::create();
    
    SetShort("Legionnaire Post");
    SetLong(
      "This small checkpoint is used to restrict access "
      "and to protect the few remaining supplies of the "
      "town's local law enforcement. Here the Legionaire "
      "take native hopeful recruits to test thier mettle "
      "before elevating them to higher rankings. To the "
      "east a descending staircase lead to the fighter "
      "barracks."
    );
    SetItems( ([
        "":""
      ]) );
    
    SetExits(([
        "out" : MY_ROOM "/barracks_e"
      ]));
    AddExit("down", 
      MY_ROOM "/classhall_fighter", (:enterHall:));
    
    
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
    
    object cm = find_living("pilus chenosa");
    object here = load_object(MY_ROOM "/legionpost");
    
    if(!present("pilus chenosa")){
        
        if(!cm || !environment(cm)) 
            cm = new(MY_NPC "/class_master_fighter");
        if(environment(cm) && environment(cm) != here)
            message("say",
              cm->GetName()+" takes her leave to relieve the guards.",
              environment(cm));
        
        cm->eventMove(here);
        
        message("say", cm->GetName()+" returns from patrol.", 
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
          "enters the barracks.", tp);
        
        return 1;
    }
    
    return 1;
} 
