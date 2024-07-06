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
    SetShort("Legionnaires Quarters");
    SetLong(
      "Before you rows of ragged and abused doubled "
      "beds are messily spaced along the  north and "
      "south sides of the barrack. Saying the beds are "
      "unmade is an understatement; it appears as if "
      "more material was used to line rodents nest than "
      "whats actually used to fill these mattresses. The "
      "walls platering is crumbling exposing bare bricks. "
      "The floor is beyiond dirty-- grimy even. Discarded "
      "armor and weapons lay in piles, some may even be "
      "of use to the needy. Portal windows are poorly "
      "boarded with gaping openings letting in streaks "
      "of light into this bleak habitat. "
    );
    SetItems( ([

      ]) );
    SetExits(([
        "up" : MY_ROOM "/legionpost"
      ]));

    ob = new(LIB_BOARD);
    ob->SetKeyName("board");
    ob->SetId( ({ "board", "fighter board" }) );
    ob->set_board_id("fighter_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(FIGHTER_COUNCIL);
    ob->SetShort( "Fighter Marching Orders");
    ob->SetLong( "Fighters Board\n");
    ob->eventMove(this_object());

}


void init() {
    ::init();
}
