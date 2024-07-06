#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

static void create() {
    ::create();

    SetClimate("indoors");
    SetShort("Galeria Ars Portalis");
    SetLong(
      "High arched columns arch up above at the domed ceiling. "
      "This design seems to be an observatory yet lacking windows. "
      "Absent of light, faintly glowing symbols provide light in this "
      "abysmal chamber."
    );
    SetItems( ([
        "arched columns" : "",
        "domed ceiling" : "",
        "observatory" : "",
        "faintly glowing symbols" : "",
        "light" : "",
        "abysmal" : ""
      ]) );
    SetExits(([
        "down" : MY_ROOM "/enclave"
      ]));
    SetInventory( ([
        "/domains/Addell/etc/portal_in" : 1
      ]) );
}

void init(){
    ::init();
}
