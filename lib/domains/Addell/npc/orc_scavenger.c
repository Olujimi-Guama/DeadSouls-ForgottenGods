#include <lib.h>
#include "../areadefs.h"

inherit ETC+ "cave_orc";

int collect, timer;

void cleanInventory(){

    int sackcheck;	
    object *obs;

    if(GetMass() <=3600  )return;

    obs = deep_inventory();

    foreach(object thing in obs){ // clear inventory
        if((base_name(thing)==OBJ+"knapsack") &&
          thing->GetWorn()) continue;
        if(thing){
            thing-> eventMove(load_object(ROOM+ "furnace"));
        }
    }

    message("info",
      "The "+GetKeyName()+" sorts through "+
      possessive()+" inventory.", 
      environment());
    return;
}

void GarbageCollector(){

    int i,j,jj;
    string objlist = "";
    object sack = present("knapsack"), 
    here = environment(this_object()), 
    *crap;

    if((timer < time()) && all_inventory(here)) {

        timer = time()+30;	    
        message( "info",
          "The orcish scavenger looks around to assess "
          "the value of the waste and if its worth picking.",
          environment(this_object()) );

        crap = all_inventory(here);
        i = sizeof(crap);

        while(i--){ // filter to only take armor, weapons, and sack

            if(strsrch(base_name(crap[i]), WEAP) ==-1  &&
              strsrch(base_name(crap[i]), ARMOR) ==-1  &&
              strsrch(base_name(crap[i]), MEALS) ==-1  &&
              strsrch(base_name(crap[i]), 
                OBJ+ "knapsack") ==-1  ){
                crap -= ({crap[i]});
                continue;
            }

            crap[i]->eventMove(this_object());
        } // ends loop

        if(sizeof(crap)){

            for(j=0,jj=sizeof(crap); j < jj; j++){
                if(jj==1){
                    objlist=add_article(crap[0]->GetShort());
                    break;
                }
                if(jj==2){
                    objlist=add_article(crap[0]->GetShort())+" and "+
                    add_article(crap[1]->GetShort());
                    break;
                }
                if(j==(jj -1 )){
                    objlist += "and "+add_article(crap[j]->GetShort());
                    continue;
                }
                else
                    objlist += add_article(crap[j]->GetShort())+", ";
            } // end loop

            message("info",
              "The "+GetKeyName()+" takes "+objlist+".", 
              environment());			
        }
    }
    cleanInventory();
}

mapping dressMe(){

    string clothing=(sex=="female"?"dress":"pants");
    mapping loadout = ([
      WEAP+ "dagger" : "wield dagger in left hand",
      ARMOR+ clothing : "wear "+clothing
    ]);

    if(random(10) < 4) collect = 1;

    if(collect && random(5) <2 ){
        loadout[OBJ+ "knapsack.c"] = "wear knapsack";
    }

    return loadout;
}

static void create() {

    string clothing;	

    ::create();

    SetKeyName("Orcish Scavenger");	
    SetId(({"orc","scavenger","waste picker"}));
    SetAdjectives(({"orcish","cave"}));
    SetShort("orcish scavenger");
    SetLong(
      "What then seemed like an oversized wild dog "
      "turns and looks upon you standing full on its heels "
      "while calculating you like a vulture to a dying animal."
    );
    SetInventory(dressMe());
    SetLevel(1);
    SetMelee(1);
    SetRace("orc");
    SetClass("fighter");
    /*
    SetSkill("knife attack", 20);
    SetSkill("knife defense", 10);
    */
    AddCurrency("copper", 100 + random(200));
    SetWanderSpeed(10);
}


void init(){

    object env = environment();
    ::init();

    if(env && clonep()){
        torch_action();
        if(collect) GarbageCollector();
        if( base_name(env) == ROOM+ "start") eventForce("go east");
    }
}
