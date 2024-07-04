//	Elohim May 2011


#include <lib.h>
#include <council.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {
    object ob;
    ::create();
    
    SetNoClean(1);
    SetNoModify(1);
    SetProperty("light", 3);
    SetProperty("night light", 2);
    SetProperty("no steal", 1);
    SetProperty("no magic", 1);
    SetProperty("no attack", 1);
    SetProperty("no castle", 1);
    
    SetClimate("indoors");
    SetShort("Clergy Prothesis");
    SetLong(
      "The prothesis is used as both an prayer room "
      "and a vestry where all the brothers that follow "
      "the path of faith can store goods to use for later "
      "or share and communicate with each other. "
    );
    SetItems( ([
        ({"prothesis","prayer room","room","vestry"}) :
        "Wouldn't it be easier just to look around?",
        "goods" : "Goods are left on the floor for "
        "general use.",
        "floor" : "You look directly down and examine "
        "the floor closely."    
      ]) );
    SetExits(([  "east" : MY_ROOM "/clergy" ]));
    
    ob = new(LIB_BOARD);
    ob->SetKeyName("Cleric Board");
    ob->SetId( ({ "board", "cleric board" }) );
    ob->set_board_id("cleric_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(CLERIC_COUNCIL);
    ob->SetShort( "Board of Acts, Gospels, and Sermons");
    ob->eventMove(this_object());
    
}

void init(){
    ::init();
}
