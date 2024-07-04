#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {
    ::create();
    
    
    SetShort("BLANK_ROOM");
    SetLong(
      "THIS ROOM NEEDS ATTENTION"
    );
    SetItems( ([
        
        // Sounds from SetListen()
        ({"prayers","chanting","chants","individuals", 
          "prayer","chant","individual"}) : "You don't "
        "see that here."
      ]) );
    SetExits(([
        "north" : MY_ROOM "/beggars_1",
        "south" : MY_ROOM "/beggars_3",
        "west" : MY_ROOM "/bridge_voss"
      ]));
    SetListen( ([
        "default" : "Prayers, chanting, and moans of pain "
        "can be heard nearby.",
        "prayers" : "You listen closely to the prayers but "
        "they are not familiar to you. Heathen.",
        ({"chanting","chants","individuals"}) : "Individuals "
        "unknown are reciting an incantation in unison.",
        ({"prayer","chant","individual"}) : "Your ears are "
        "not trained well enough to pull that off."
      ]) );
}

void init(){
    ::init();
}
