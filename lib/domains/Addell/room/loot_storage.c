#include <lib.h>
#include "../areadefs.h"

inherit TMPL;


int read_sign();

static void create() {
    ::create();

    SetShort("Looting Storage Room");
    SetLong(
      "This is the local general store. You can buy or sell "
      "items here. A sign on the wall hangs here, explaining "
      "how things work.  East Village Road is "
      "south of here. The storeroom is below."
      "\nTry \'read sign\'."
    );
    SetItems(([
        ({"store","shop","place"}) : "This is the local store.",
        ({ "sign" ,"sign on the wall" }): "A sign on the wall, "
        "meant for reading.",
      ]));
    SetExits( ([
        "south" : ROOM+ "cavepass9"
      ]) );
    SetInventory(([
        NPC+ "gorm" : 1
      ]));
    SetRead("sign", (: read_sign :) );
}

int read_sign(){
    write("Even if you understood the orcish "
      "tongue its written too sloppily.");
    return 1;
}

void init(){
    ::init();
}
