#include <lib.h>
#include ROOMS_H
inherit LIB_ITEM;
inherit LIB_PRESS;

int check_environs();
int vanish_count = 50;
int presses = 3;


static void create() {
    item::create();

    AddSave( ({ "presses", "vanish_count" }) );
    SetKeyName("omni");
    SetAdjectives( ({"strange","small"}) );
    SetId(({"omni", "device"}));
    SetShort("strange device");
    SetLong(
      "This is a small, round metal device, copper in color, "
      "with a hinged lid covering a cage with internal "
      "mechanism. Little metal discs surround a blue "
      "and green sphere. There is a red jewel emitting a "
      "pulsing light of red next to the tiny metal button "
      "opposite of it's hinged end."
    );
    SetMass(10);
    SetDollarCost(300);
    AddItem("button", "A button on the omni.");
    AddItem(({"light","red light"}) , "A pulsing red light.");
    AddItem(({"sphere","blue and green sphere"}), "");
    AddItem(({"discs","metal discs","little metal discs",
        "disc","metal disc","little metal disc"}),"");
}

void init() {
    ::init();

    check_environs();
}

mixed CanPress(object who, string target) {
    if(!present(this_object()->GetKeyName(),who ) && 
      target == "button"){
        return "You do not have the device!";
    }
    if(this_object()->GetId() == target){
        return "You cannot push that.";
    }
    return 1;
}

mixed eventPress(object who, string where) {

    object *rooms = objects( (: inherits(LIB_ROOM, $1) :) );
    object target;
    int success = 0;


    if(!presses){
        write("Click.");
        return 1;
    }

    /*
    rooms = filter(rooms, (: member_array(
        base_name($1), ({ ROOM_START, ROOM_FURNACE,
        ROOM_VOID, ROOM_POD, ROOM_DEATH, ROOM_WIZ,
        ROOM_ARCH, ROOM_NETWORK, ROOM_ROUTER, 
        LIB_FURNACE,  ROOM_FREEZER }) ) == -1  && 
                strsrch(base_name($1),"/realms/") &&
        !inherits(LIB_FURNACE,$1) && !($1->GetVirtual() &&
        !grepp(base_name($1),",")) && 
        last_string_element(base_name($1),"/") != "death" :) );
        */
    say(who->GetName()+" turns "+
      dbz_colors("multicolored")+" and disappears!");
    write("You feel momentarily disoriented and find "
      "yourself elsewhere!");
    while(!success){

        //target = rooms[random(sizeof(rooms)-1)];
        target = load_object(ROOM_START);	
        success = who->eventMove(target);

    }

    presses--;

    who->eventDescribeEnvironment();
    tell_room(target, 
      "With a multicolored flash, "+ who->GetName()+ 
      " appears!",
      who);

    return 1;
}

void heart_beat(){

    object *holders = filter(containers(this_object()),
      (: interactive($1) :) );

    if(sizeof(holders)) vanish_count--;
    if(vanish_count < 0){
        tell_object(environment(),
          "The device glows brightly and disappears!" );
        this_object()->eventDestruct();
    }

    if(vanish_count == 5){

        tell_object(environment(),
          "The device begins to glow a dull red.");
        this_object()->
        SetLong(
          "This is a small, round metal device, copper in color, "
          "with a hinged lid covering a cage with internal "
          "mechanism. Little metal discs surround a blue "
          "and green sphere. There is a red jewel emitting a "
          "dim light of red next to the tiny metal button "
          "opposite of it's hinged end."
        );
        this_object()->SetShort("strange device (glowing)");
    }
}

int check_environs(){
    if( interactive(environment()) ){
        set_heart_beat(10);
    }
    return 1;
}
