#include <lib.h>
#include "../areadefs.h"

inherit LIB_BANK;

int ReadSign();
string LongDesc();




static void create() {
    
    bank::create();
    
    SetProperty("no attack", 1);
    
    SetClimate("indoors");
    SetAmbientLight(30);
    
    SetTown("Roses");
    SetAmbientLight(30);
    SetShort("M. Gibbons & Co. [BANK]");
    // "GetLong OVERRIDDEN (that's what she said)"
    SetLong( (:LongDesc:) );
    SetItems( ([
        "sign" : "A sign you can read.",
        "litter" : "Scraps of paper and refuse.",
        ({"scraps","paper","refuse"}) : "You looks at the litter "
        "blowing about as if it were the most beautiful thing in the world.",
        ({"bank","building"}) : "What one assumes to be"
        "the only excuse for a financial institution in town.",
      ]) );
    SetExits(([
        "out" : MY_ROOM "/_square",
        //"down" : MY_ROOM "/vault" //future implementation
      ]));			
    SetInventory(([	MY_NPC "/roses_banker" : 1  ]));	
    SetRead( ({"sign","sign hanging here"}) , (: ReadSign :) );
}


void reset() { //Just defined here for future additions
    ::reset();
    
}




string LongDesc(){
    
    string _LONGDESC = "Once a welcome center for wary travellers "
    "this restructured building has long been occupied "
    "for financial endeavors. The worn and tired hall "
    "is littered with whatever the breeze blows in. "
    "Discolored plaster decorate the wall leaving only one "
    "barred window available. \n";
    
    if(!present("ROSES_BANKER_001020"))
        return _LONGDESC +"Although the teller is suspiciously absent, "
        "%^GREEN%^you can read a sign hanging here.%^RESET%^";
    else return (_LONGDESC + "The teller looks up long enough from his penknife manicure to point at "
          "%^GREEN%^a sign you can read hanging here.%^RESET%^");
}




int ReadSign(){
    write( 
      
      "\n- This bank requires a minimum balance to open an account. "
      "To use any of the bank's services, you must first open an "
      "account (see below as to how).\n"
      
      "- This bank charges for certain transactions, such as"
      "currency exchange.\n\n"
      
      "To conduct business here:\n\n"
      
      "request account from TELLER\n"
      "request balance from TELLER\n"
      "ask TELLER to deposit AMOUNT CURRENCY\n"
      "ask TELLER to withdraw AMOUNT CURRENCY\n"
      "ask TELLER to exchange AMOUNT CURRENCY for CURRENCY\n\n"
      
      "examples:\n\n"
      
      "request account from teller\n"
      "request balance from teller\n"
      "ask zoe to deposit 100 silver\n"
      "ask teller to withdraw 10 silver\n"
      "ask teller to exchange 10 gold for silver\n"
      
    );
    return 1;
}
