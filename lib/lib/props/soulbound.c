/*	/lib/props/soulbound.c
  *
  *	Libray object to create objects
  *	players cannot drop, give away,
  *	put in other objects (item 
  *	smuggling) or sell
  *
  *	created on: 20110729
  *	created by: Elo'him@ForgottenGods
  */	

//	Last Modified: 20110731 by Elo

//GetLastEnvironment()


#include <lib.h>
#include <function.h>

inherit LIB_PERSIST;
inherit LIB_OBJECT;


private mixed bound = 0;

// begin abstract methods

varargs SetRetainOnDeath();
varargs SetPreventDrop();
varargs SetPreventGet();
varargs SetPreventPut();
string GetName();
string GetCoreDesc();
string GetExternalDesc();
string GetDefiniteShort();

// end abstract methods


int GetSoulBound(){ 
	if( intp(bound) ) return bound;
	if( functionp(bound) ) return evaluate(bound, this_object());
	
	// it's not a func or a int so its no good to us
	return 0;
	}

	
void RunSoulBound(){
 
// This can be called directly
//although I couldn't guess as to why
	
mixed responsePrevent;	

responsePrevent = bound?"You cannot do that with the "+
	  remove_article((string)GetShort())+"; it is soul bound.":0 ;

SetPreventDrop(responsePrevent);
SetPreventGet(responsePrevent);
SetPreventPut(responsePrevent);
SetRetainOnDeath(bound);
	
return;
}
	
	
int SetSoulBound(mixed val){
	

	if(intp(val)){
	bound = val;
	RunSoulBound();
	return bound;
	}
	
	else if( !(functionp(val) & FP_OWNER_DESTED) ) {
	bound = evaluate(val, this_object());
	RunSoulBound();
	return 1;
	}

	// it's not a func or a int so its no good to us
	return 0;    
}


mixed CanSell(){ 
	if (!GetSoulBound()) return 1;
	
	return "You cannot do that with the "
		+(string)GetShort()+" because it is a soulbound item.";
	
	return !GetSoulBound(); 
	}

string GetExternalDesc(){

	if( GetSoulBound() ) 
		return GetCoreDesc()+"\n%^BOLD%^The "+
		GetDefiniteShort()+" is soulbound.%^RESET%^";

else return GetCoreDesc();
}

string array GetSave(){
    return ({ "bound" });
}

static mixed array AddSave(){
	return persist::AddSave( ({"bound"}) );
	}
	
	
void init(){
// no need to make the master soulbound!
	write("\n[debug]: "+file_name()+" all clear.");
if(clonep() & functionp(bound)){
	
	bound;
	}
}
