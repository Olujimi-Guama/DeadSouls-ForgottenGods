#include <lib.h>
inherit LIB_ROOM;
#include "../areadefs.h"

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Gorm's storage room");
    SetLong("This is a small, bare room where Gorm keeps his goods. The main store is above.");
    SetInventory(([
        OBJ +"skin" : 5,
        OBJ +"match" : 5,
        OBJ +"torch" : 5,
        WEAP +"axe" : 5,
        WEAP +"dagger" : 5,
        WEAP +"javelin" : 5,
        WEAP +"sword" : 5,
        ARMOR +"armored_boot_l" : 2,
        ARMOR +"armored_boot_r" : 2,
        ARMOR +"armored_glove_r" : 2,
        ARMOR +"armored_glove_l" : 2,
        ARMOR +"chainmail" : 5,
        ARMOR +"leather_armor" : 5,
        ARMOR +"orc_boot_r" : 5,
        ARMOR +"orc_boot_l" : 5,
        ARMOR +"orc_tallboot_r" : 5,
        ARMOR +"orc_tallboot_l" : 5,
        ARMOR +"orc_helmet" : 5,
        ARMOR +"platemail" : 1,
        ARMOR +"pants" : 10,
        ARMOR +"dress" : 10,
      ]));
    SetExits( ([ 
        "up" : ROOM+ "shop",
      ]) );
    SetNoClean(1);

}

int CanReceive(object sneak) {
    object *living_stack = get_livings(sneak);
    if(!living_stack || !arrayp(living_stack)) 
        living_stack = ({ sneak });
    foreach(object ob in living_stack){
        if(living(ob) && !creatorp(ob) &&
          !member_group(ob,"TEST")) {
            message("info",
              "Otik's back room is for authorized personnel only.", 

              ob); 
            return 0;
        }
    }
    return 1;
}

void init(){
    ::init();
}
