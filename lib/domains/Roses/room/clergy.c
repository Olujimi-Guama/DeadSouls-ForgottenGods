//	Elohim Feb 2010
//  	ROOM TEMPLATE for the city of Roses

#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int enterHall();
int makeFurniture();
int findClassMaster();

static void create() {
    ::create();
    
    SetClimate("indoors");
    SetShort("Clergy Templon");
    SetLong(
      "Inside the monastery's templon new priests are admitted "
      "into a path of faith. Although not initiated into any specific "
      "order, many have come here professing thier devotion to thier "
      "beliefs. The walls are lined with scrolls that are studied and "
      "scrutinized by travellers and religious students alike. Reliefs "
      "are carved into the wood supports with various religious "
      "motifs depicted throughout."
    );
    SetItems( ([
        "monastery's templon" : "",
        "walls" : "",
        "scrolls" : "",
        "Reliefs " : "",
        "wood supports" : "",
        "religious motifs" : ""
      ]) );
    //	SetInventory(([  MY_OBJ "/case" :1   ]));
    SetExits(([  "north" : MY_ROOM "/monastery" ]));
    AddExit("west", 
      MY_ROOM "/classhall_cleric",(:enterHall:));
    
    makeFurniture();
    findClassMaster();
}

void init(){
    ::init();
    
    findClassMaster();
}

void reset(){
    ::reset();
    
    makeFurniture();	
}


int makeFurniture(){
    
    object ob;
    
    if(!present("desk_1542", this_object())){
        
        ob = new(LIB_SURFACE);
        
        ob->SetKeyName("wooden table");
        ob->SetId( ({"desk_1542","desk"}) );
        ob->SetAdjatives(({"large","oak","wooden"}));
        ob->SetShort("large oak desk");
        ob->SetLong(	  
          "This desk is used for clergy registration purposes."
        ); 
        //ob->SetInventory((["/domains/default/obj/handbook" : 1 ]));
        ob->SetMaterials( (["oak":100]) );
        ob->SetMass(274);
        ob->SetPreventGet("You decide to leave the desk in place.\n"
        );
        ob->SetBaseCost("silver",1);
        ob->SetMaxCarry(5000);
        ob->inventory_visible();
        ob->inventory_accessible();
        ob->eventMove(this_object());
    }
    
    if(!present("chair_1542", this_object())){
        
        ob = new(LIB_CHAIR);
        
        ob->SetKeyName("wooden chair");
        ob->SetId( ({"chair_1542","chair"}) );
        ob->SetAdjatives(({"red","oak","wooden","leather","padded"}));
        ob->SetShort("leather padded chair");
        ob->SetLong(	  
          "This chair is used for clergy registration purposes."
        ); 
        ob->SetMaterials( (["oak":75,"leather":15,"wool":10]) );
        ob->SetMass(274);
        ob->SetPreventGet("You decide to leave the chair in place.\n"
        );
        ob->SetBaseCost("silver",1);
        ob->eventMove(this_object());
        
    }
    
    return 1;
}

int findClassMaster(){
    
    object cm = find_living("Scholar Fidelis");
    object here = load_object(MY_ROOM "/clergy");
    
    if(!present("Scholar Fidelis")){
        
        if(!cm || !environment(cm)) 
            cm = new(MY_NPC "/class_master_cleric");
        if(environment(cm) && environment(cm) != here)
            message("say",
              cm->GetName()+" disappears into a ball of holy light.",
              environment(cm));
        
        cm->eventMove(here);
        
        message("say", cm->GetName()+" arrives from "
          "the vestry.", 
          here);
        cm->eventForce("sit in chair");
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
          "enters the sacred hall.", tp);
        
        return 1;
    }
    
    return 1;
}
