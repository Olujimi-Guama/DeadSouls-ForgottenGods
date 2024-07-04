#include <vision.h>
#include ROOMS_H
#include <lib.h>
#include "../areadefs.h"

inherit LIB_SENTIENT;

int throwing;
string sex="", desc="";

void OrcGenerator(){

    sex = ({"male","female"})[random(2)];

    if(20 > random(100)){
        new(WEAP+ "javelin")->
        eventMove(this_object());
    }

    SetGender( sex );
    SetRace( "orc" );
    SetLanguage( "Tangetto", 100 );

    if (sex == "male" || sex == "female"){

        desc = " "+(sex=="female"?"Her":"His")+
        " countenance is brutal. "+(sex=="female"?"She":"He")+
        " stands bow-leg and haunched over; not fully "
        "humanoid yet not quite a beast. "+
        (sex=="female"?"She":"He")+" seems smaller in size "
        "than the average man. "+(sex=="female"?"Her":"His")+
        " brutish apperance looks further repulsive above all-- "+
        (sex=="female"?"she":"he")+" looks like a burn victim "
        "completely covered in gore and filth.";
    }

    else 
        desc = " It's countenance is brutal. It stands "
        "bow-leg and haunched over; not fully humanoid yet not "
        "quite a beast. It seems maller in size than the average "
        "man. It's brutish apperance looks further repulsive above "
        "all-- it looks like a burn victim completely covered in gore "
        "and filth.";	

}


static private string *exempted = ({ "orc","half-orc",
  "rodent","bear" });
int GetEnemyChaser() { return 1; }

void JavFunc(){
    object env = room_environment(this_object());
    if(throwing) throwing--;
    if(GetInCombat()){

        object targ;
        object jav = present("javelin",this_object());
        object *targs = filter(get_livings(env), 
          (: member_array($1, GetEnemies()) != -1 :) );

        if(sizeof(targs)) 
            targ = targs[random(sizeof(targs)-1)];
        if(present("javelin", env)){
            eventForce("get a javelin");
            jav = present("javelin",this_object());
        }

        if(jav && targ && !throwing){
            eventForce("throw a javelin at "+targ->GetKeyName());
            throwing = 10;
        }
    }
}

int CheckOrc(mixed val){

    if(!val) return 0;
    if(!objectp(val)) return 0;
    if(creatorp(val)) return 0;
    if(member_array(val->
        GetRace(),exempted) != -1) return 0;
    eventForce("growl at "+val->GetKeyName());
    if( this_object()->GetEnemyChaser() &&
      !this_object()->GetLeader() && 
      sizeof(filter(val->GetFollowers(),
          (: base_name($1) == 
            base_name(this_object()) :))) < 1){
        eventForce("follow "+val->GetKeyName());
        SetWanderSpeed(1);
    }

    return 1;
}

// The following function simply makes an orc light a torch
// with a match if it's dark. It looks complicated because there
// will be a bunch of orcs, and a bunch of torches, and a bunch
// of matches. This function makes sure that THIS orc lights
// THIS torch with THIS match, thereby avoiding a cave choked to
// the gills with matches, torches, and blind orcs.

int torch_action(){
    object torch, match;
    object *tmp, *tmp2;
    int x, y;

    if(this_object()->GetEffectiveVision() < VISION_CLEAR){

        tmp = filter(all_inventory(this_object()), 
          (: answers_to("match", $1) && $1->GetLit() :) );
        tmp2 = filter(all_inventory(this_object()), 
          (: answers_to("torch", $1) && 
            $1->GetFuelAmount() :) );

        if(sizeof(tmp)) match = tmp[0];
        if(sizeof(tmp2)) torch = tmp2[0];
        if(!torch){
            tmp2 = filter(all_inventory(this_object()), 
              (: answers_to("torch", $1) :) );
            if(sizeof(tmp2)) tmp2->eventMove(ROOM_FURNACE);
            torch = new(OBJ+ "torch");
            torch->eventMove(this_object());
        }

        if(!match){
            tmp = filter(all_inventory(this_object()),
              (: answers_to("match", $1) :) );
            if(sizeof(tmp)) tmp->eventMove(ROOM_FURNACE);
            match = new(OBJ+ "everstrike_match");
            match->eventMove(this_object());
        }

        if(torch && match){

            x = (environment(torch) && 
              environment(torch) == this_object());
            y = (environment(match) && 
              environment(match) == this_object());

            if(x && y){
                string torchname = torch->GetUniqueId();
                string matchname = match->GetUniqueId();
                if(!match->GetLit()){
                    this_object()->eventForce("strike my match");
                }
                this_object()->
                eventForce("light "+torchname+" with "+
                  matchname );
            }
        }
    }

    if(torch && torch->GetLit()){
        this_object()->eventForce("drop my match");
    }
    return 1;
}

void create(){
    ::create();
    if(clonep())OrcGenerator();
}

void init(){
    object env = environment();
    ::init();
    if(env && base_name(env) == ROOM+ "start"){
        eventForce("go east");
    }
}

void heart_beat(){
    object env = environment();
    if(!clonep()) return;
    ::heart_beat();

    if(this_object()->GetEffectiveVision() < VISION_CLEAR){
        torch_action();
    }

}

varargs mixed SetGuard(mixed what, 
  mixed action, int howlong){
    return ::SetGuard(what, action, howlong);
}

string GetExternalDesc(){ return GetCoreDesc() + desc; }
