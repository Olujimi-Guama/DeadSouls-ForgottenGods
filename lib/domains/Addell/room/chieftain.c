#include <lib.h>
#include ROOMS_H
#include "../areadefs.h"

inherit TMPL;

string ImprovedLong(){

  object lever;
  string desc = "This is a dark, foreboding underground room, the lair of an orc "
  "warchieftain. The walls are rough and adorned with crude markings and trophies "
  "of past battles. Passageways lead south and north, guarded by the warchieftain's "
  "loyal minions. ";

  if( !(lever = present( "lever", 
    this_object())->GetSprung() )){
      desc += "The floor of the cave under you is a haphazard assembly of shoddy "
      "timber and planks, barely holding together. The wood is warped and splintered, "
      "with gaps between the planks that reveal the dark void below. Each step you take "
      "causes the floor to creak ominously, as if it might give way at any moment. "
      "The construction is so poor that it's clear this floor was built in haste, with "
      "little regard for safety or stability.";
  }
  else{
    desc += "The section of the floor is revealed to be a gaping entrance to the depths "
    "below. The worn edges withrusted hinges marking the edge of darkness."; 
  } 

  return desc;
}

void create() {
    ::create();

    

    SetAmbientLight(0);
    SetShort("orc warchieftain's lair");
    SetLong( (: ImprovedLong :) );
    
    SetItems( ([
        ({ "ground", "rock", "rocks", "earth", "dirt", "stone", "stones" }) : 
            "The ground is rough and dirty, littered with bones and debris from countless skirmishes.",
        ({ "wall", "walls", "rough walls", "adorned walls", "marked walls" }) : 
            "The walls are carved roughly into the earth, adorned with crude markings and trophies "
            "that tell tales of the warchieftain's conquests.",
        ({ "passage", "passageway" }) : 
            "These passageways provide access to other parts of the underground stronghold, "
            "guarded by the warchieftain's loyal orcs.",
        ({ "room", "here", "area" }) : 
            "This room, carved roughly into the earth, serves as the lair of the orc warchieftain, "
            "a place of power and intimidation.",  
        ({ "floor", "timber", "planks", "wood" }) : 
            "The floor of the cave under you is a haphazard assembly of shoddy timber and planks, barely holding together. "
            "The wood is warped and splintered, with gaps between the planks that reveal the dark void below. Each step you take "
            "causes the floor to creak ominously, as if it might give way at any moment. The construction is so poor that it's clear "
            "this floor was built in haste, with little regard for safety or stability.",
        ({ "floor", "section of the floor", "entrance", "trap door" }) : 
            "The section of the floor is revealed to be a gaping entrance to the depths below. "
             "The worn edges with rusted hinges mark the edge of darkness."
    ]) );
    
    
    SetSmell( ([
        "default" : "The air is thick with the stench of sweat, blood, and the lingering odor "
        "of unwashed bodies.",
        ({ "sweat", "blood" }) : "The overwhelming stench of stale and dried bodily fluids "
        "assults the  olfactory senses.",
        ({ "lingering ordor", "odor", "unwashed bodies", "bodies"}) : "The lingering stank of the "
        "occupants of this cave system."
      ]) );
    SetListen( ([
      ({ "default" }) : "You hear the distant clamor of orcish voices, the clinking of weapons, and "
      "the occasional roar of the random orc."
    ]) );
    

    SetInventory(([
        OBJ+ "tall_lamp" : 1,
        ETC+ "lever" : 1,
        OBJ+ "chest1" : 1,
        NPC+ "chieftain" : 1,
      ]));
    SetExits( ([ 
        "north" : ROOM+ "cavepass9",
        "south" : ROOM+ "cavepass13",
      ]) );
}

void init(){
    ::init();
}
