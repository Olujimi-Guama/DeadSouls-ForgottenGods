#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;
inherit LIB_SOULBOUND;

void prsItem();


static void create(){
    armor::create();

    SetKeyName("hosen");
    SetAdjectives( ({"simple"}) );
    SetId( ({ "hosen" }) );
    SetShort( "simple hosen" );
    SetLong(
	"gamboised simple hosen"
		);
    SetProtection( PHYS_DAMAGE, 1 );
    SetArmorType( A_LONG_SOCK );
    SetMaterials( ([ "textile" : 100 ]) );
    SetValue( 0 );
    SetMass( 1 );
    }


void init(){
    ::init();

	if( clonep() ) prsItem();
}

string GetExternalDesc(){

	if( newbiep(environment()) )
		return GetCoreDesc()+"\n%^BOLD%^The "+
		GetDefiniteShort()+" is soulbound.%^RESET%^";

else return GetCoreDesc();
}


int GetRetainOnDeath(){
  if( !environment() || !living(environment()) ) return 0;
  else return newbiep(environment());
}

mixed eventMove(mixed dest) {

	if( environment()  &&  newbiep(environment()) ) return 0;

	else return armor::eventMove(dest);;
}


void prsItem(){

	mapping imapp = ([]);

if(!environment() || !living(environment())) return;

	switch ( environment()->GetRace() ) {

		case "noor":
			imapp = ([
			"name" : "slacks",
			"adj" : ({"simple"}),
			"id" : ({ "slacks","hosen" }),
			"short" : "simple slacks",
			"long" : "",
			]);

		break;

		case "nuar":
			imapp = ([
			"name" : "loincloth",
			"adj" : ({"simple"}),
			"id" : ({ "loincloth","hosen" }),
			"short" : "simple loincloth",
			"long" : "",
			]);
		break;

		case "vorskh":
			imapp = ([
			"name" : "chausses",
			"adj" : ({"simple"}),
			"id" : ({ "chausses","hosen" }),
			"short" : "simple chausses",
			"long" : "",
			]);
		break;

		default:
		imapp = ([
			"name" : "hosen",
			"adj" : ({"simple"}),
			"id" : ({ "hosen" }),
			"short" : "simple hosen",
			"long" : "",
			]);
	}

	SetKeyName(imapp["name"]);
	SetAdjectives( imapp["adj"] );
	SetId( imapp["id"] );
	SetShort( imapp["short"] );
	SetLong( imapp["long"] );

return;
}
