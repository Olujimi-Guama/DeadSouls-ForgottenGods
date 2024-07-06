#include <lib.h>
#include <vendor_types.h>
#include "../areadefs.h"

inherit LIB_ITEM;

int searched;


string SearchCrap(){

    string result;

    if(!searched){
        if(!random(1000)){
            result="Rummaging through the disgusting pile, "
            "you discover a beautiful gold ring mixed in with "
            "the crap.";
            say(this_player()->GetName()+
              " searches a pile of debris and seems to have found "
              "something of value.");
            if(!new(ARMOR+ "ring")->eventMove(this_player()))
                new(ARMOR+ "ring")->eventMove(
                  environment(this_object()));

            searched=1;

            return result; 
        }
    }

    result="You rummage through the disgusting pile "+
    "and find nothing.";
    say(this_player()->GetName()+" searches a pile of debris "
      "with no results.");
    searched=1;

    return result; 
}


void create(){
    ::create();

    SetKeyName("garbage");
    SetId( ({"pile","debris","crap","crud"}) );
    SetAdjectives( ({"disgusting","pile of","smelly"}) );
    SetShort("a pile of garbage");
    SetLong("This is a smelly, disgusting pile of garbage.");
    SetMass(2000);
    SetDollarCost(0);
    SetSearch( (: SearchCrap :) );
    SetNoCondition(1);
    SetPreventGet("The pile of debris isn't at all portable.");
}

void init(){
    ::init();
}
