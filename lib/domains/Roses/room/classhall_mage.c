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
    SetShort("Cabal Esoterium");
    SetLong(
      "As you enter the esoterium a large stonework floor artfully "
      "crafted is spread out befor you. Vaulted windows rise up "
      "with smaller portal windows set above,. The stained glass "
      "plays light along the floor. bookcases full of arcane and "
      "eldritch studies line the walls. Furniture is set to allow the "
      "traveling members rest and arranged for in depth "
      "discussion of the magi level-- such as the transduction of "
      "latent energies within the spiritual and physical bodies of "
      "existence."
    );
    SetItems( ([

      ]) );
    SetExits(([
        "east" : MY_ROOM "/enclave"
      ]));

    ob = new(LIB_BOARD);
    ob->SetKeyName("board");
    ob->SetId( ({ "board", "mage board" }) );
    ob->set_board_id("mage_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(MAGE_COUNCIL);
    ob->SetShort( "Journals of the Arcane");
    ob->SetLong( "Random musings and "
      "observations of the pratictioners of Arcane Studies.\n");
    ob->eventMove(this_object());

}


void init() {
    ::init();
}
