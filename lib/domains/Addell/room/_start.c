#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit LIB_ROOM;

int DoZone(string);

void create()
{
  ::create();

  SetClimate("arctic");
  SetNightLight(15);
  SetDayLight(25);
  SetAmbientLight(5);
  SetTown("Addell Grottos");
  SetCoordinates("999000,999000,999000");
  SetShort("Entrance to Addell Grottos");
  SetLong(
      "This is a small cave near a riverbank. The entrance is framed by jagged rocks, "
      "and the air is crisp and cold. The sound of the river can be faintly heard in "
      "the distance.");
  SetNightLong(
      "This is a grotto carved into the rocky riverbank wall. The cave opens west into "
      "the night, where the moonlight casts eerie shadows on the walls. To the east is "
      "darkness, where the cave continues deeper into the earth.");
  SetDayLong(
      "This is a grotto carved into the rocky riverbank wall. Daylight shines in from "
      "the west, where the river flows, illuminating the rough-hewn walls. To the east, "
      "the cave continues into darkness, inviting further exploration.");
  SetItems(([
      ({
    "wall", "rocky wall", "river bank wall", "riverbank wall",
      "rocky river bank wall", "rocky riverbank wall"}):
        "The local river carved a narrow and steep valley here over the years. The walls "
        "of that valley are what this cave has been dug out of. The rock is cold to the "
        "touch and covered in patches of frost.",
      ({ "entrance", "cave entrance"}):
          "The entrance to the cave is framed by jagged rocks, giving it a foreboding "
          "appearance. The ground here is uneven, with loose stones scattered about.",
      ({ "river", "riverbank"}):
          "The river flows nearby, its waters cold and clear. The sound of the river can be "
          "faintly heard, adding a sense of tranquility to the otherwise harsh environment."
          ]) );
SetExits(([
    //"west" : ROOM+ "riverbank",
    "east":ROOM + "cavepass1",
  ]));

AddExit("west", ZONE_OUT, (: DoZone :) );

SetInventory(([ETC + "portal_out":1]));
}

void init()
{
  ::init();
}

int CanReceive(object ob)
{
  int pass = load_object(ROOM + "cavepass1")->bouncer(ob);
  return pass;
}

int DoZone(string dir)
{

  write("\n%^BOLD%^CYAN%^A supernatural force blocks your movement!%^RESET%^\n"
        "The same protection that keeps the beasts and monsters out also keeps you in!\n");
  say("The same protection that keeps the beasts and monsters out also keeps " +
      possessive_noun(this_player()->GetName()) + " in!\n");

  if (wizardp(this_player()))
    message("say",
            "[WIZ][BUILDER] EXIT RESERVED FOR NEW DOMAIN! -Elo\n",
            this_object());

  return 0;
}