//	Elohim Feb 2010


#include <lib.h>
#include "../areadefs.h"

inherit MROOM;


static void create() {
    
    ::create();
    
    SetShort("Westgate Tower");
    SetLong(
      "The wall looms high keeping the town safe. The thick grass grows "
      "along the stone walkway, some spots growing wilder than others. "
      "The gatehouse is barely discernible behind the growth of wild "
      "phorusweed."	
    );
    SetItems( ([
        "wall" : "A massive stone wall.",
        ({"thick grass","grass spots","grass spot","grass","spots","spot"}) : 
        "The grass grows in spots. These spots of wild grass thicken near "
        "the gatehouse.", 
        ({"stone walkway","walkway"}) : "The stone walkway starts at the "
        "top of the steps and lead westard towards the guardhouse.",
        ({"gatehouse","tower base","base of the tower","base"}) : "The "
        "gatehouse sits at the base of the tower.",
        ({"tower","structure"}) : "The tower rises up and connects to the "
        "paraport. From here you can see that pieces of the structure had "
        "crumbled exposing a hole on it's side.",
        "paraport" : "The paraport stretches from this tower eastward over "
        "the gates.",
        ({"gates","gate"}) : "You don't see that from here. Consider "
        "moving closer to the east.",
        ({"wild phorusweed", "phorusweed","weed","stonebush"}) : 
        "Phorusweed, known locally as stonebush, grows wildly here "
        "drawing minerals from the stone."
      ]) );
    SetExits(([
        "east" : MY_ROOM "/merchant_n2",
        "west" : MY_ROOM "/wall_w2"
      ]));
    SetEnters( ([
        "gatehouse" : MY_ROOM "/westgate_f1"
      ]) );	
}


void init(){
    ::init();
}
