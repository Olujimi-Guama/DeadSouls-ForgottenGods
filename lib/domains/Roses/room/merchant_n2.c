//	Elohim Feb 2010
//  Flavor room for the city of Roses


#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int DoZone(string);


static void create() {
    
    ::create();
    
    SetShort("Merchants and Wall");
    SetLong(
      "A cobbled road leads to the north away from the grand wall "
      "before trailing north to the northern wilds. To both the "
      "east and west the early stoneworks has "
      "carved steps into the packed earth rising from the sides of "
      "the road. Two gate towers rise from the rockheads found "
      "surrounding the town's border with a parapet stretched "
      "adjoining them overhead."
    );
    SetItems( ([
        ({"cobbled road","road"}) : "Not much to look at. Sections "
        "have been carried off or just went wayside over the years.",
        ({"north","gate"}) : "The gate looms north surrounded by the "
        "massive wall.",
        ({"grand wall","massive wall","wall","wall stonework"}) : 
        "The large wall, made of stone mined from the distant quarries, "
        "rises high above the town. This end the road past the gates "
        "meets the valley below outside a sheer drop from teh wall.",
        ({"northern wilds","northern wild","wilds","wild","valley"}) : 
        "The northern wilds are home to all the cruel scary beasts of "
        "stories children were told by their parents. You try to look "
        "past the gate but to no avail.",
        ({"material","stoneworks"}) : "Although crude and almost "
        "barbaric, the stonework both on the wall, east, and west "
        "have survived the centuries.",
        ({"east stoneworks","east"}) : "The steps to the east have been "
        "carved into the elevated sides of packed earth leading off to "
        "East Wall.",
        ({"west stoneworks","west"}) : "The steps to the west have been "
        "carved into the elevated sides of packed earth lazily rising up "
        "towards the West Wall.",
        ({"carved steps","carved step","steps","step"}) : "The stone "
        "material were said to be cut by hand and fitted in place by "
        "teams of men in the thousands. The thought of why has such a "
        "citadel that is known of in all the legends and folklore has "
        "diminished to such a ragged town in desperate disrepair.",
        ({"packed earth","earth"}) : "On the side of the road you can "
        "see what seems to be where probably some retaining wall stood. "
        "The earth on either side has eroded to some degree; the roots "
        "of trees can be seen in some spots. You can only wonder how "
        "magnificient this all was when first built.",
        ({"sides","side"}) : "You look on either side and wonder if "
        "heavy rainfalls or melting snow buries this place in mud.",
        ({"gate towers", "towers"}): "The towers rise on either side "
        "of the gate, up, up, until they reach the parapet.",
        ({"gate tower", "other tower","tower"}): "Looks very much like the "
        "other tower. How long you planning to do this?",
        ({"rockheads","rockhead","foundation"}) : "You can still see some of "
        "the natural formation used as the foundation for the stoneworks.",
        "border" : "The wall marks the town's border.",
        ({"parapet","overhead"}) : "Overhead the parapet link and crosses "
        "the gate towers."
      ]) );
    SetExits(([
        "east" : MY_ROOM "/wall_e1",
        "west" : MY_ROOM "/wall_w1",
        "south" : MY_ROOM "/merchant_n1"	
      ]));
    
    //use this to link to new area
    AddExit("north", MY_ROOM "/merchant_n2", (: DoZone :));
}


void init(){
    ::init();
}




int DoZone(string dir){
    
    write("\n%^BOLD%^CYAN%^A supernatural force blocks your movement north!%^RESET%^\n"
      "The same protection that keeps the beasts and monsters out also keeps you in!\n");
    say("The same protection that keeps the beasts and monsters out also keeps "+
      possessive_noun(this_player()->GetName())+" in!\n" 	);
    
    if(wizardp(this_player()))	
        message( "say",	
          "[WIZ][BUILDER] EXIT RESERVED FOR NEW DOMAIN! -Elo\n",
          this_object() );			     
    
    return 0;
}
