//  	ROOM TEMPLATE for the city of Roses

#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {
    ::create();
    
    SetClimate("indoors");
    SetShort("Eastgate Staircase");
    SetLong(
      "The stone stairs connect the lower entrance "
      "of the gatehouse to the chambers above. The "
      "amount of negligence is evident in the crumbling "
      "and mildew growing in the dank recesses where "
      "shadows linger."
    );
    SetItems( ([
        ({"stone stairs", "stone stair", "stairs", "stair"}) : 
        "The stone stairs are crumbling from the lack of "
        "care. It is hard to find footing in this darkness.",
        ({"lower entrance", "gatehouse", "entrance"}) : 
        "The gatehouse below looks much more ",
        ({"chambers above","chamber above", "chambers", 
          "chamber"}) : "Looking up you only see darkness "
        "there.",
        ({"negligence", "crumbling", "steps", "step",
          "stone steps", "stone step", "broken stone steps",
          "broken stone steps"}) : "The steps are in poor "
        "condition.",
        ({"dank recesses", "dank recess", "recesses", 
          "recess","mildew"}) : "Very little light enters from below "
        "to the advantage of the pathces of mildew growing in "
        "the dank, darker reccesses in the broken stone steps.",
        ({"shadows", "shadow", "darkness", "above"}) : "Try "
        "as you might but you cannot make out anything above."
      ]) );
    SetExits(([  
        "up" : MY_ROOM "/eastgate_f2",
        "down" : MY_ROOM "/eastgate_f1"
      ]));
    
}

void init(){
    ::init();
}
