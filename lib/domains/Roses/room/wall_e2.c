//	Elohim Feb 2010
//  	ROOM TEMPLATE for the city of Roses

#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {

    ::create();


    SetShort("East End");
    SetLong(	//think this is skim description? Room reserved for future use :)
      "Here Wall ends into the bordering mountainside of the valley. "
      "Patches of grass cover the ground." 
    );
    SetItems( ([
        ({"massive wall","wall"}) : "The massive wall ends here "
        "as if melting into the mountainside",
        ({"bordering mountainside","mountainside","bordering mountain side",
          "mountain side"}) : "The wall was seemlessly fitted into the mountainside.",
        ({"town","valley"}) : "The town was built in this valley.",
        ({"patches of grass","patches","patch","grass patch","ground"}) : 
        "Having nothing better to do you begin to exaime the patches of grass."
      ]) );
    SetExits(([
        "west" : MY_ROOM "/wall_e1"	
      ]) );
}


void init(){
    ::init();
}
