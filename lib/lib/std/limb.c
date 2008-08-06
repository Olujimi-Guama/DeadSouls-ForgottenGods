/*    /lib/std/limb.c
 *    From the Dead Souls Object Library
 *    Standard limb object for severed limbs
 *    Created by Descartes of Borg 950329
 *    Version: @(#) limb.c 1.5@(#)
 *    Last Modified: 96/12/31
 */

#include <lib.h>
#include <medium.h>

inherit LIB_SURFACE;

int Count          = 0;
string Limb        = 0;
string Owner       = 0;
string Race        = 0;
int CallOut = -1;
int stank, nodecay, slowdecay;

int eventDecay();

string GetLimb(){
    return Limb;
}
string GetItemCondition(){
    return "";
}

void create(){
    surface::create();
}

void init(){
    surface::init();
    if(environment() && environment()->GetMedium() == MEDIUM_LAND) stank = 1;
}

void SetLimb(string limb, string owner, string race){
    string justlimb;
    sscanf(limb,"%*s %s",justlimb);
    SetKeyName(limb);
    SetId( ({ limb, "flesh","pile","limb",(justlimb||"chunk") }) );
    SetAdjectives(({"severed","rotting",race}));
    Limb = limb;
    Owner = owner;
    Race = race;
    Count = 1;
    SetShort("a rotting " + possessive_noun(Race) + " " + Limb);
    SetLong("This limb has a horrible stench as it rots to nothing.");
}

string GetOwner(){
    return Owner;
}

string GetRace(){
    return Race;
}

int GetSaveString(){
    return 0;
}

string GetShort(){
    string str = surface::GetShort();

    if( !str ){
        str = "a limb";
    }
    return str;
}

int CanReceive(object ob){
    return 1;
}

int Destruct(){
    return surface::Destruct();
}

int eventDecay(){
    if( !environment() ){
        Destruct();
        return 0;
    }
    switch(Count){
    case 10:
        if(stank)
            message("smell", "The "+Limb+" really stinks.", environment());
        SetShort("the stinky remains of a rotting " + Limb);
        break;
    case 20:
        if(stank)
            message("smell", "A rotting stench fills the entire area.",
              environment());
        SetShort("a pile of rotting flesh");
        break;
    case 30:
        Destruct();
        return 0;
    }
    if(slowdecay){
        if(random(100) > slowdecay) Count++;
    }
    else Count++;
    return Count;
}

int SetNoDecay(int i){
    if(i) nodecay = 1;
    else nodecay = 0;
    return nodecay;
}

int GetNoDecay(){
    return nodecay;
}

int SetSlowDecay(int i){
    if(i) slowdecay = i;
    else slowdecay = 0;
    return slowdecay;
}

int GetSlowDecay(){
    return slowdecay;
}

int SetCount(int i){
    Count = i;
    return Count;
}

int GetCount(int i){
    return Count;
}

