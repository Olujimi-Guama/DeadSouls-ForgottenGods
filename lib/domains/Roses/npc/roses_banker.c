#include <lib.h>
#include <vendor_types.h>
#include "../areadefs.h"

inherit LIB_TELLER;


string GetMyName(){
    
    if( !environment(this_object()) ) return "Monte the non-descript";
    if( present("roses_bank_guard_54564", environment(this_object())))return "Monte G the Arrogant";
    else return "Monte G, the Fearful Coward";
    
}


int SummonGuard(mixed val){
    
    object ob;
    
    if(present("roses_bank_guard_54564", environment(this_object()))|| !val || !objectp(val)) return 0;
    
    
    if(val->GetLevel() <= 10){
        message("say",
          "The teller smugly says: Welcome, don't cause any trouble here, maggot.",
          environment(this_object()));
        return 0;
    }
    else 
        message( "say",
          "The teller looks nervous and quickly grabs a passing guard. \n",
          environment(this_object()) );
    message( "say",
      "The teller tells the guard: %^CYAN%^Stand here and protect me.%^RESET%^",
      environment(this_object()) );
    message( "say",
      "The guard sighs and says: %^CYAN%^Great, wonder who I'm replacin'.%^RESET%^\n",
      environment(this_object()) );
    
    
    ob = new(LIB_NPC);
    
    ob->SetKeyName("Newly Appointed Bank Guard");
    ob->SetId( ({"bank guard", "guard", "roses_bank_guard_54564" }) );
    ob->SetShort("Bank Guard");
    ob->SetLong(
      "This shabby guard has been suckered into accepting "
      "this post. He jumps at every shadow and sound. It is no "
      "secret that any fool taking this post is not seen around "
      "by the following season."
    );
    ob->SetLevel(10);
    ob->SetRace("human");
    ob->SetClass("fighter");
    ob->SetGender("male");
    ob->set_alignment(200);
    ob->SetInventory(([ MY_WEAP "/sword.c" : "wield sword" ]));
    ob->SetStat("strength",40);
    
    ob->eventMove(environment(this_object()));
    
    return 0;
}

static void create() {
    ::create();
    
    SetKeyName("Monte");
    SetId( ({ "teller","banker","executive", "ROSES_BANKER_001020" }) );
    SetAdjectives( ({ "bank","executive","friendly","efficient" }) );
    SetShort( (: GetMyName :) );
    SetLevel(12);
    SetLong(
      "A shape-less, dirty little man, Monte appears as a pile "
      "of horse-puke took life and decided to pursue a career in "
      "banking. The talk around town speaks of his family line in "
      "Roses dating back to the aristocratic lords that keep the "
      "peace and financial order for the empire. This must have "
      "been long ago for few graces are lost on this man. \n"
      "He appears fidgety jumping at his own shadow."
    );
    SetGender("male");
    SetMorality(40);
    SetRace("human");
    AddCurrency("silver", random(100));
    SetProperty("no bump", 1);
    SetBankName("M. Gibbons & Co.");
    SetLocalCurrency("silver");
    SetLocalFee(1);
    SetOpenFee(5);
    SetExchangeFee(2);
    SetCurrencies( ({ "dollars", "copper", "silver", "electrum", "gold", "platinum" }) );
    SetPolyglot(1);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetEncounter(  (: SummonGuard :) );
}
