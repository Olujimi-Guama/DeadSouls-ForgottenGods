#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

void makeBeggars();


static void create() {
    ::create();
    
    SetShort("BLANK_ROOM");
    SetLong("1-3 beggars");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    
    SetExits(([
        "north" : MY_ROOM "/beggars_2",
        "east" : MY_ROOM "/bandits_1",
      ]));

 makeBeggars();	
}


void init(){
    ::init();
}


void reset(){
	::reset();
	
 makeBeggars();
}


void makeBeggars(){
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
	
    while(!present("bum "+i)) {	
     int ii = random(sizeof(dSize));
     ob = new(LIB_NPC);
    
    ob->SetKeyName(dSize[ii]);
    ob->SetId( ({dSize[ii],"bum"}) );
    ob->SetShort( dSize[ii] );
    ob->SetLong( dDesc[ii] );
    ob->SetLevel( dLevel[ii] );
    ob->SetRace("human");
    ob->SetClass("explorer");
    ob->SetGender("male");
    ob->set_alignment(-(random(4)));
    
    ob->eventMove(this_object());
    }
    
    return;
	
}