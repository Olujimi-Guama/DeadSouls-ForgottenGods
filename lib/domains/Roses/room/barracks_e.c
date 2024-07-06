#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

void QuackQuack();

static void create() {
    ::create();
    
    
    SetShort("BLANK_ROOM");
    SetLong("Random 3 waterfouls");
    SetItems( ([
        "template" : "That's what this is.",
        // dummy items
        ({"barracks","barrack"}) : ""
      ]) );
    
    SetExits(([
        "west" : MY_ROOM "/merchant_s1"
      ]));
    AddEnter( "barracks", MY_ROOM "/legionpost" );
	  
  QuackQuack();
}

void init(){
    ::init();
}

void reset(){
	::reset();
	
	QuackQuack();
	}
	

void QuackQuack(){
    
    object ob;
	
	int i = 3 + random(3);
	int *dLevel = ({3,2,1});
	string *dSize = ({
	    "large mallard","small mallard","mallard duckling"
		});
	string *dDesc = ({
		"A large drake with a "
		+(random(10)>4?"blue":"green")+
		" neck, head, and dark brown "
		"speckled feathers over it's body.",
		"A small brown speckled mallard duck",
		"A small awkward duckling still plumed in down."
			});
	
    while(!present("duck "+i)) {	
     int ii = random(sizeof(dSize));
     ob = new(LIB_NPC);
    
    ob->SetKeyName(dSize[ii]);
    ob->SetId( ({dSize[ii],"mallard","bird","duck"}) );
    ob->SetShort( dSize[ii] );
    ob->SetLong( dDesc[ii] );
    ob->SetLevel( dLevel[ii] );
    ob->SetRace("bird");
    ob->SetClass("explorer");
    ob->SetGender("neuter");
    ob->set_alignment(random(4));
    
    ob->eventMove(this_object());
    }
    
    return;
}