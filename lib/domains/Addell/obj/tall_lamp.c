#include <lib.h>
#include <vendor_types.h>

inherit LIB_TORCH;


void create(){
    ::create();

    SetKeyName("lamp");
    SetId( ({"lamp","tall lamp"}) );
    SetAdjectives( ({"crude","tall","oil","floor"}) );
    SetShort("tall oil lamp");
    SetLong(
      "This is a tall oil floor lamp, very crudely made."
    );
    SetPreventGet("The lamp is embedded into the floor.");
    SetMass(20);
    SetBaseCost("copper", 60);
    SetVendorType(VT_TREASURE);
    SetRadiantLight(25);
}

void init(){
    ::init();

    if(!GetLit() && CanBurn(this_object())){
        this_object()->eventBurn(0,0,1);
    }
}

