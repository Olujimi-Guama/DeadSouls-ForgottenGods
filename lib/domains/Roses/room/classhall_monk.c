//	Elohim May 2011
//	Classhall for monk
//	Rogue stock classhall 
//	used as reference


#include <lib.h>
#include <council.h>
#include "../areadefs.h"

inherit MROOM;



static void create() {

    object ob;
    ::create();

    SetNoClean(1);
    SetNoModify(1);

    SetProperties( ([
        "light" : 3, "night light" : 2, "no steal" : 1,
        "no attack" : 1, "no castle" : 1
      ]) );
    SetClimate("indoors");
    SetShort("Sacred Hall of the Empty Fist");
    SetLong(
      "You stand inside a covered hallway used by "
      "monks as a centralized location to meet and "
      "communicate with others. The section of walls "
      "between pillars are adorned with painted "
      "portraits of the ancestors that heavily influenced "
      "this order of warrior priests. Earthly trappings "
      "and material possessions that burden the pietistic "
      "soul are left here for others to make use of when "
      "neccessary."
    );
    SetItems( ([
        ({"hallway","covered hallway"}) : "This covered "
        "hallway is the meeting place for all orders of monks.",
        ({"walls","section of walls"}) : "The section of walls "
        "between the pillars are adorned with portraits.",
        "wall" : "You stare at the wall and find nothing "
        "noteworthy.",
        ({"pillar","pillars"}) : "Pillars are arranged in pairs along "
        "the wall supporting the roof.",
        "roof" : "You stare above you and find nothing noteworthy.",
        ({"portraits","painted portraits"}) : "These are different "
        "images of past ancestors.",
        ({"ancestor","ancestors"}) : "The portraits are images of "
        "monks and priests that defined what warrior priests, known "
        "as monks, are known as today.",
        ({"earthly trappings","trappings","trappings",
          "material possessions","possessions","possession"}) : "What "
        "one can find stored here in this hall may discover bliss and "
        "serenity. Also helps to look around."
      ]) );
    SetExits(([
        "east" : MY_ROOM "/courtyard"
      ]));

    ob = new(LIB_BOARD);
    ob->SetKeyName("board");
    ob->SetId( ({ "board", "monk board" }) );
    ob->set_board_id("monk_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(MONK_COUNCIL);
    ob->SetShort( "Message Board of the Unified Order");
    ob->SetLong( "News and notices are posted here for "
      "all orders and brotherhoods to review.\n");
    ob->eventMove(this_object());

}


void init() {
    ::init();
}
