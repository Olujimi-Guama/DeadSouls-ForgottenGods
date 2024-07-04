#include <lib.h>
#include <position.h>
#include "../areadefs.h"

inherit MROOM;

int PostMaster();
int PostMan(string);




static void create(){
    
    ::create();
    
    SetClimate("indoors");
    
    SetShort("Messenger Station");
    SetLong(
      "You enter a small office with a counter seperating "
      "all who enter from the small wooden cubbyholes "
      "containing letters from and to the citizens of Roses. "
      "Behind the counter a space that can only house one "
      "serves as the center of this office's operations."
    );
    SetItems( ([ 
        ({"box","boxes","mailboxes","mailbox"}) : "Rows of mailboxes for "+
        "the denizens of Frontiers.",
        "sign" : "This is a sign on the wall describing how to mail messages.",
        ({"wall","walls"}) : "Gray-painted institutional walls of the kind you'd "+
        "expect in a post office.",
        "implements" : "Ink, paper, etc.",
        "instructions" : "Try reading them.",
        "counter" : "A counter folks use to lean on while writing messages." 
      ]) );
    SetExits(([
        "out" : MY_ROOM "/_square"
      ]));	
    AddExit("up", MY_ROOM "/_post", (: PostMan :));
    PostMaster();
}


void init(){
    ::init();
    PostMaster();
}


void reset(){
    ::reset();
    PostMaster();
}





int PostMaster(){
    
    object ob;
    
    if(this_object() && !present("roses_post_master_95482", this_object())){
        
        message("say",
          "The post master walks in silently, tossing out "
          "an empty mug of ale, before resuming his station. \n",
          this_object() );
        
        ob = new(LIB_NPC);
        
        ob->SetKeyName("Post Master Mav");
        ob->SetId( ({"mav", "postmaster", "post master", "roses_post_master_95482" }) );
        ob->SetShort("Post Master; Mav");
        ob->SetLong(
          "Although greying, the post master carries an air "
          "of dignity and professionalism. Occasionally chasing "
          "dust off his shoulder before returning to his simple "
          "crossword puzzles. You would never imagine that "
          "this same man makes the occasional mistake of sending "
          "a message to the wrong recipient often more than "
          "naught for some very humorous results."
        );
        ob->SetLevel(10);
        ob->SetRace("half-elf");
        ob->SetClass("fighter");
        ob->SetGender("male");
        ob->set_alignment(100);
        ob->SetStat("strength",40);
        ob->SetPosition(POSITION_SITTING); //it isn't working but whatever NS FEB 2010
        ob->SetAction(20, ({ 
            "\nA carrier runs in, collects a letter to deliver from "
            "the postmaster, then runs off.\n"
          }));
        
        ob->eventMove(this_object());
        
        
        
        return 1;
    }
    
    else return 0;
}




int PostMan(string dir){
    
    if(present("roses_post_master_95482", this_object()) && 
      living(present("roses_post_master_95482",this_object())) ) {
        
        write("Mav looks up from his crossword puzzle and examines you momentarily.\n");
        say("Mav looks up from his crossword puzzle and examines " + 
          possessive_noun(this_player()->GetName()) + " momentarily.\n");
        
        if(this_player()->GetTown() != this_object()->GetTown()){
            
            if(wizardp(this_player())){
                
                message( "say",
                  "Mav mumbles: Not like I can stop you... go ahead. \n",
                  this_object() );
                
                return 1;
            }
            
            message( "say",
              "Mav yells: Hey you can't go in there! Roses citizens only! \n",
              this_object() );
            
            return 0;
        }  
        
        else 
            message( "say",
              "Mav tips his hat and continues on to his crosswords. \n",
              this_object() );
        
        return 1;
    }
    
    else return 1;
}
