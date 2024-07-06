//	Flavor room for the city of Roses
//	an example of exploded long description
//	The long desc was copied to SetItems()
//	then broken down into items including
//	descriptors or adjetives.
//	note, for example:
//	line 27 "declines northward" and line 40 "northward decline"
//	it helps to have some grasp of English!


#include <lib.h>
#include "../areadefs.h"

inherit MROOM;




static void create() {
    
    ::create();
    
    SetShort("North Merchants");
    SetLong(
      "What was once busy roads now lay in ruin. Where a proud "
      "boulevard was covered in rich cobblestone now only lay "
      "bare in waste. The road elevates south towards the "
      "square. To each side earth walls the road as it "
      "declines northward towards Wall-- cradling it "
      "with-in her bosom and providing level ground for "
      "buildings surrounding the square."
    );
    SetItems( ([
        ({"busy roads", "busy road", "roads", "road"}) : "You examine "
        "the road closely, unimpressed.",
        ({"proud boulevard", "boulevard"}) : "Another town fallen into "
        "disrepair and decrepitude.",
        ({"rich cobblestone", "cobblestone"}) : "No longer a topic of "
        "pride, the cobblestones are scattered about as the denizens "
        "picked them off as materials for building.",
        ({"denizens", "denizen", "people"}) : "You stare at random "
        "people and they either walk off in a faster pace or glare back.",
        ({"bare waste", "waste", "muddy road."}) : "Segments have been "
        "reduced to muddy road.",
        "south" : "You look south where the road rises toward the square.",
        "square" : "You cannot see that clearly from where you stand.",
        "side" : "The ground remains level as the road in the center "
        "declines, forming earth walls to teh side.",
        ({"earth walls", "walls"}) : "The earth walls were once retained "
        "by stone. As with most of the town, materials were carried off "
        "for use in other more morally pressing use.",
        "earth wall" : "After years of wild growth and the elements ",
        "wall" : "Are you trying to look at the earth walls or the north "
        "at the city wall.",
        ({"city wall", "north"}) : "The city wall becomes more "
        "discernible from this vantage.",
        ({"northward decline", "north decline", "decline"}) : "The road "
        "declines north as it approaches the wall.",
        ({"her bosom", "bosom"}) : "Seriously?",
        ({"level ground", "ground"}) : "The grounds have been leveled as "
        "a foundation to the surrounding buildings.",
        ({"surrounding buildings", "buildings", "building"}) : "From here "
        "you recognize the bank and post office.",
        ({"post office", "bank"}) : "Although you can make out some of "
        "the surrounding buildings they are not accessable from your "
        "current location."
      ]) );
    SetExits(([
        "north" : MY_ROOM "/merchant_n2",
        "south" : MY_ROOM "/_square"	
      ]));
}

void init(){
    ::init();
}
