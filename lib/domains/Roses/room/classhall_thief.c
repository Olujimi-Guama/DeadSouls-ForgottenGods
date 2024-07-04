//	Elohim April 2011
//	Classhall for thief
//	Rogue stock classhall 
//	used as reference


#include <lib.h>
#include <council.h>
#include "../areadefs.h"

inherit MROOM;



static void create() {

    object ob;
    ::create();

    SetNoClean(1);
    SetNoModify(1);
    SetProperty("light", 3);
    SetProperty("night light", 2);
    SetProperty("no steal", 1);
    SetProperty("no magic", 1);
    SetProperty("no attack", 1);
    SetProperty("no castle", 1);

    SetClimate("indoors");
    SetShort("Abandoned Breastworks of the City Gates");
    SetLong(
      "The covered parapet is used as a central gathering room "
      "and vault. Here the brotherhood leave behind lesser "
      "goods for others to utilize to thier own needs. The walls "
      "are adorned with art between the windows and a warm "
      "fire burns in a central pit. A strange mist swirls in the "
      "doorway to the west."
    );
    SetItems( ([
        ({"covered parapet","parapet","central gathering room",
          "gathering room","vault","gatehouse"}) : "You are in it.",
        "house" : "Did you mean this gatehouse?",
        "room" : "Did you mean thsi gathering room?",
        ({"brotherhood","others"}) : "The collective underground in Roses.",
        ({"lesser goods","goods","good"}) : "Usually piled on the floor "
        "anyone is invited to share. after all, it can all be stolen back.",
        ({"walls","wall"}) : "The walls in this room have windows and adorned with art.",
        "windows" : "There are windows along the wall.",
        "window" : "Upon closer inspection the windows have been tarred and covered "
        "in grime preventing outside notice.",
        "grime" : "The grime is thick and blacks out the window.",
        ({"warm fire","fire"}) : "The fire crackles brightly.",
        ({"central pit","pit"}) : "A pit centered in the room made from stones losened "
        "from debris scattered through the remains of the gatehouse.",
        ({"debris","remains","useless remains"}) : "Useless remains. It is scattered all "
        "over this gatehouse.",
        ({"painting", "art"}) : "You don't recognize the language well enough to read "
        "but they seem to depict a folk-god named Amirani",
        ({"doorway","west","swirl","strange swirl"}) : "A dark swirl seems to be "
        "absorbing all the light from the otherside of the doorway."
      ]) );
    SetExits(([
        "east" : MY_ROOM "/eastgate_f2",
        "west" : MY_ROOM "/westgate_f2"
      ]));

    ob = new("/lib/bboard");
    ob->SetKeyName("board");
    ob->SetId( ({ "board", "thief board" }) );
    ob->set_board_id("thief_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(ROGUE_COUNCIL);
    ob->SetShort( "Brotherhood's Board of Fiendish Plots");
    ob->SetLong( "On this rotting wood board, thives come to post "
      "of bounties dastardly deeds, and other fiendish foils "
      "for other rogues to see.\n");
    ob->eventMove(this_object());

}


void init() {
    ::init();
}
