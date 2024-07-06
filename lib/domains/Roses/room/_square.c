//	Written by Elohim	Feb 2010
//	for the
//	Forgotten Gods Mud

#include <lib.h>
#include "../areadefs.h"

inherit MROOM;

int DemonFang();   
//future implementation for demon areas



void create() {
    object ob;
    ::create();
    
    // safehaven/startroom properties
    SetNoModify(1);
    SetProperty("light", 3);
    SetProperty("night light", 2);
    SetProperty("no steal", 1);
    SetProperty("no magic", 1);
    SetProperty("no attack", 1);
    SetProperty("no castle", 1);	    
    
    SetShort("Chevalier Square");
    SetLong(
      "Once the hub of a great empire, now "
      "the center of rot and decay. You "
      "stand in Chevalier Square. Historically "
      "where a proud citizenry hailed newly "
      "knighted nobles and received news from "
      "lands afar. Now all that is left is "
      "a testiment of the decay and rot "
      "set upon by generations of abuse from "
      "the castes and absense of fair law. \n"
      "Here, new adventurers congregate to "
      "admire, even envy, more established "
      "and reknown ilks of their kind. Parade "
      "Avenue intersects Merchants Boulevard "
      "in this black heart of the city. "
    );
    SetItems( ([
        "adventurer" : "You are caught staring and "
        "look away in shame.",
        "adventurers" : "You admire their courage "
        "and craftiness.",
        ({"avenue","parade avenue"}) : "Once the "
        "envy of the empire now it lays desolute and "
        "in disrepair.",
        ({"merchants boulevard", "merchants boulevard"}) : 
        "Once a bustling boulevard full of customers "
        "has fallen wayside to thugs and cutthroats.",
        ({ "thug", "thugs", "cutthroat", "cutthroats" }) : 
        "If they were to be that obvious they really "
        "wouldn't be a problem, right?"
      ]) );
    SetExits( ([
        "north" : MY_ROOM "/merchant_n1",
        "south" : MY_ROOM "/bridge_reid",
        "east" : MY_ROOM "/parade_e1",
        "west" : MY_ROOM "/parade_w1",
        "northeast" : MY_ROOM "/_bank",
        "northwest" : MY_ROOM "/post_lobby"		
      ]) );
    SetInventory(([ MY_NPC "/than" : 1  ]));
    SetListen("You hear random spots of conversation and "
      "sounds of travel.");
    SetSmell("The smell of mild rot and unwashed masses "
      "is buffered by the artic air.");
    
    ob = new(LIB_BOARD);
    ob->SetKeyName("gnarled tree");
    ob->SetId( ({ "tree", "gnarled tree", "board" }) );
    ob->set_board_id("_square_board");
    ob->set_max_posts(25);
    ob->SetShort( "Gnarled Tree");
    ob->SetLong( 
      "Messages are nailed on this gnarled tree to communicate "
      "the going-ons of the town or anything in general.\n"
    );
    ob->eventMove(this_object());
    
}

void init(){
    ::init();
    DemonFang();
}

int DemonFang(){
    
    if(!present("roses_square_monolith_18348", this_object())){
        
        object ob = new(LIB_ITEM);
        
        message( "say", "\n"
          "You sense a shimmer out of the corner of your eye "
          "and realize a massive monolith you overlooked when "
          "you first arrived. \n",
          this_object() );
        
        ob->SetKeyName("Demon Fang");
        ob->SetId( ({"demon fang", "fang", "monolith", "stone", 
            "roses_square_monolith_18348" }) );
        ob->SetAdjatives(({"dark", "granite", "mighty", "massive"}));
        ob->SetShort("Dark Granite Monolith");
        ob->SetLong(	  
          "The monolith rises high, smooth and polished granite "
          "surfaces display odd characters that can only be described "
          "as ancient writing. The old ones here say that here the "
          "gods marked the site of a great citadel that pre-dated "
          "Roses by centuries after a great demon was defeated. You "
          "are somewhat dubious of these stories on account to the "
          "smooth and unmarked surfaces of this mighty, massive stone."
        );    
        ob->SetRead(
          "The shadows of the carved lettering shimmers before "
          "your eyes as you can only make out some of the message \n"
          "%^BOLD%^BLACK%^\n"
          "partum deus elo'him is castellum ex suus somes quod "
          "accersitus continuo vita in illa nex rectus %^RESET%^\n" 
        );
        ob->SetPreventGet( "\n%^BOLD%^\n"+
          "The gods laugh at you as you try to move what they set in "
          "place.%^RESET%^\n");
        
        ob->eventMove(this_object());
        
        return 1;
    }
    
    else if(random(10) > 7)
        
        message( "say", "\n"
          "The monolith seems to visually pulsate as if "
          "summoning... someone? \n", this_object() );
    
    return 1;
}
