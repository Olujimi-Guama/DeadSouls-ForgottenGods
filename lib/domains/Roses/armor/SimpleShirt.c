/*
gamboised

Body	Jerkin
Hands	Gloves
Legs	 Chausses
Feet	Ledelsens

Body	Tunic
Hands	Gloves
Legs	Slacks
Feet	Boots

Body	Separates
Hands	Gauntlets
Legs	Loincloth
Feet	Gaiters
*/
  // override eventDestruct()?


#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;
inherit LIB_SOULBOUND;

int sbItem();
void prsItem();


static void create(){
    armor::create();

    SetKeyName("shirt");
    SetAdjectives( ({"simple"}) );
    SetId( ({ "shirt" }) );
    SetShort( "simple shirt" );
    SetLong(
	"gamboised simple shirt"
		);
    SetProtection( PHYS_DAMAGE, 1 );
    SetSoulBound( sbItem() );
    SetArmorType( A_SHIRT );
    SetMaterials( ([ "textile" : 100 ]) );
    SetValue( 0 );
    SetMass( 1 );
    }


void init(){
    ::init();

	RunSoulBound();
	if( clonep() ){ prsItem(); }

}

int sbItem(){

	return creatorp(environment());
}


void prsItem(){

	mapping imapp = ([]);

if(!environment() || !living(environment())) return;

	switch ( environment()->GetRace() ) {

		case "noor":
			imapp = ([
			"name" : "tunic",
			"adj" : ({"simple"}),
			"id" : ({ "tunic","shirt" }),
			"short" : "simple tunic",
			"long" : "A simple tunic",
			]);

		break;

		case "nuar":
			imapp = ([
			"name" : "body wraps",
			"adj" : ({"simple"}),
			"id" : ({ "body wraps","hosen" }),
			"short" : "simple body wraps",
			"long" : "A simple body wraps",
			]);
		break;

		case "vorskh":
			imapp = ([
			"name" : "jerkin",
			"adj" : ({"simple"}),
			"id" : ({ "jerkin","shirt" }),
			"short" : "simple jerkin",
			"long" : "A simple jerkin",
			]);
		break;

		default:
		imapp = ([
			"name" : "shirt",
			"adj" : ({"simple"}),
			"id" : ({ "shirt" }),
			"short" : "simple shirt",
			"long" : "A simple shirt",
			]);
	}

	SetKeyName(imapp["name"]);
	SetAdjectives( imapp["adj"] );
	SetId( imapp["id"] );
	SetShort( imapp["short"] );
	SetLong( imapp["long"] );


return;
}
