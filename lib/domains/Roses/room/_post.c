#include <lib.h>
#include <objects.h>
#include <post.h>
#include "/lib/include/post_office.h"
#include "../areadefs.h"

inherit LIB_ROOM;




static void create(){
    
    room::create();
    
    SetProperty("no attack", 1);
    
    SetAmbientLight(30);
    SetClimate("indoors");
    
    SetTown("Roses");
    SetShort("Roses Post Office");
    SetLong(
      "Here privacy is given to citizens of Roses to check "
      "their correspondence. Although not as bleak as other "
      "facilities in Roses, layers of dust coat the fixtures "
      "and the wooden postal units. \n"
      "A set of instructions has been posted on the wall "
      "near the entrance for your convenience."
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
    SetExits( ([
        "down" : MY_ROOM "/post_lobby.c",
      ]) );
}


void init(){
    ::init();
    add_action("instr","read");
}




int instr(string str){
    
    if(str=="instructions"||str=="sign"){
        
        write(
          "To mail someone, type mail <person's name here>.\n"
          "Enter a subject line.\n"
          "Enter your message.\n"
          "Once you've finished, enter a period (.) on a blank line.\n"
          "Hit x, then s to send it. You're done!\n"
        );
        return 1;
    }
}




mixed CanMail(object who, string args) {
    if( !interactive(who) ) return 0;
    if( GetTown() != who->GetTown() )
        return "%^BOLD%^----***This is not your home town***----%^RESET%^\n"
        "Any mail you might have will be at your home post office.";
    return 1;
}




mixed eventMail(object who, string args) {
    object ob;
    
    if( !(ob = new(OBJ_POST)) ) {
        who->eventPrint("Failed to load postal object!");
        return 1;
    }
    
    if( !(ob->eventMove(who)) ) {
        who->eventPrint("You can't seem to carry the postal object.");
        return 1;
    }
    
    ob->start_post(args);
    return 1;
}




int CanReceive(object ob) {
    if( !ob && !(ob = previous_object()) ) return 0;
    if( living(ob) && !interactive(ob) ) return 0;
    else return room::CanReceive(ob);
}




int eventReleaseObject() {
    
    object ob;
    
    if( !(ob = previous_object()) ) return room::eventReleaseObject();
    if( !room::eventReleaseObject() ) return 0;
    if( (ob = present(POSTAL_ID, ob)) ) ob->eventDestruct();
    return 1;
}
