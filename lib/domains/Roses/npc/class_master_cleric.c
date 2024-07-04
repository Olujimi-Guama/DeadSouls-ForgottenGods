/*    /domains/Ylsrim/npc/fighter.c
 *    From the Dead Souls Mud Library
 *    An example class leader
 *    Created by Lassondra@Dead Souls
 */

#include <lib.h>
#include "../areadefs.h"

inherit LIB_TRAINER;

//static string save_file = save_file("/domains/Ylsrim/save/roshd");
//static string quest_object = "/domains/town/armor/orc_helmet";
//string *ok_join = ({});

int sosTimer;

int JoinGuild(object ob, string verb, string what);
int PreviewGuild(object who, string verb, string what);
int TeachFeat(object who, string verb, string feat);
int eventAssist(object ob, string verb, string what);


int AllowPass(object who, object what){

    if(who->GetClass() == "cleric") return 1;

    if(wizardp(who)){
        write(GetName()+" is oblivious to your presence.");	
        return 1;
    }

    return ::AllowPass(who, what);
}

int CheckVisitor(object who){

    eventForce("shake");
    eventForce("say Sorry friend, only those of the clergy "
      "are allowed to pass.");

    return 0;
}


int combatHelp(){

    string *assailant = ({});
    string name;
    int i = sizeof(GetEnemies());

    if(time() < sosTimer) return 0;

    sosTimer = (time() + 10);

    foreach(object jerk in GetEnemies()){
        if((name=jerk->GetName()) == "A shadow"){
            name = "unknown attacker";
        }  
        if ((i > 1) && (jerk == GetEnemies()[i - 1]))
            name = "and "+name;
        assailant += ({name});
    }

    sosTimer += 5;

    eventForce("cleric %^B_BLUE%^WHITE%^BOLD%^"+
      "HELP! I'm being attacked by "+implode(assailant, ", ")+
      "!%^RESET%^");
}



static void create() {
    trainer::create();

    SetKeyName("Scholar Fidelis");
    SetId("fidelis", "trainer", "cleric","scholar");
    SetShort("Scholar Fidelis Judge-in-Absence of the Order");
    SetLong(
      "This small man seems as a pale ghost lost with-in his dark "
      "brown wooly robes. His alburn hair is pulled back where it "
      "vanishes in the shadows of his vestments. His face is "
      "adorned with blue markings that seem ritual. They circle "
      "around his right eye and streak paths along his right temple "
      "and cheek. His long arms barely stretch past the long sleeves "
      "of his cloak, his manicured nails teasingly displayed but not "
      "accentuated.\n"	
      "\nFidelis initiates new members into the ways of "
      "the warrior-priests, the monks. Although he has "
      "no real authority to initiate anyone he still jabbers "
      "on.\n"
      "If you are considering following thier path, you can "
      "%^CYAN%^BOLD%^<ask Fidelis for help>%^RESET%^."
    );
    SetRace("vorskh");
    SetClass("cleric");
    SetLevel(45);
    SetGender("male");
    SetMorality(400);
    SetProperty("no bump", 1);
    SetAutoStand(0);
    SetGuard("west", (: CheckVisitor :));
    SetLanguage("Common", 100);
    SetDefaultLanguage("Common");
    SetNoSpells(1);
    SetCombatAction(100, (: combatHelp :));
    AddTrainingSkills(({
        "magic defense", "faith", "healing", "blunk attack", "blade defense"
      }));
    // stick him on the fighter line
    if( clonep() ) {
        AddChannel("cleric");
    }
    SetCommandResponses( ([
        "train" : (: eventTrain :),
        "teach" : (: eventTrain :),
        "default" : (: eventHelp :),
        "help" : (: eventHelp :),
        "join" : (: JoinGuild :),
        "preview" : (: PreviewGuild :)
      ]) );
    AddRequestResponses( ([
        "help" : (: eventHelp :),
      ]) ); 
}


int eventHelp(object ob, string what){
    ::eventHelp(ob, what);

    if(ob->GetClass() != "cleric") {
        eventForce("say Did you come all this way to ask me about "
          "being a cleric?");

        if(ob->GetClass() != "explorer") {
            eventForce("say I'm afraid you've wasted your time.");
            eventForce("say It's a well known fact that anyone studied in "
              +capitalize(ob->GetClass())+" arts would make a poor cleric.");
            return 1;
        }

        eventForce("say Well, you can ask to preview cleric if you're interested.");	
        return 1;
    }
    return 1;
}

int JoinGuild(object ob, string verb, string what){

    string name = ob->GetName();

    if(ob->GetClass() == "cleric") {
        eventForce("say How mant times you think you can become a cleric?");

        return 1;
    }
    eventForce("say Interested in following the path of the faithful?");

    if(ob->GetClass() == "explorer" || !ob->GetClass()){
        eventForce("say very well, "+name+".");
        write("The Scholar initiates you into the faithful path.");
        write(name+" becomes a cleric.", ob);
        ob->ChangeClass("cleric");
        ob->init_skills("cleric");
        ob->SetLoginSite( MY_ROOM "/classhall_cleric" );
        ob->AddTitle("the "+
          (ob->GetGender()=="female"?"Matron":"Patron")+
          " of the Amatuer Healers");
        if( ob->GetMorality()  < 0 ){
            eventForce("say "+name+", under the authority vested in me, "
              "you are hereby absolved of all your past crimes.");
            ob->SetMorality(0);
        }
        eventForce("say Welcome to the faith!");
        eventForce("laugh");
        eventForce("say You can come to me for training when ready.");

        return 1;
    }

    eventForce("say I'm afraid a "+capitalize(ob->GetClass())+
      " does not have a place here");
    eventForce("say The "+capitalize(ob->GetClass())+"'s Guild "
      "would be most upset about losing you.");
    return 1;
}

int PreviewGuild(object ob, string verb, string what){
    string keyname = ob->GetKeyName();
    string name = ob->GetName();

    if(ob->GetClass() == "cleric") {

        eventForce("say You have already given yourself to the faith!");
        return 1;
    }

    if(ob->query_class() != "explorer") {
        eventForce("say My humble apologies, "+name+
          ", you have no place here.");
        return 1;
    }

    say(name+" asks about following the faithful path.",
      ob);

    eventForce("laugh w");
    eventForce( "whisper to "+keyname+" "
      "To give yourself unto something only so deeply true in your "
      "heart and soul is truely a miracle. To follow this path of faith "
      "you have to decide what direction you choose to go." );
    eventForce( "whisper to "+keyname+" "
      "I will induct you into our esteemed guild where your faith will "
      "mold you into a councilor, a judge, wanderer or student. Which "
      "orders and gods you decide upon bestowing your belief is "
      "entirely your decision.");
    eventForce( "emote utters a small prayer." );
    eventForce( "whisper to "+keyname+" "
      "Listen, young "+(ob->GetGender()=="male"?"boy":"one")+
      " I can only hope that you avoid the trappings of this earth "
      "and stay true to the betterment of all that walk this earth.");
    eventForce( "whisper to "+keyname+" "
      "I can only ask that you are the light for those in the darkest places "
      "and righteousness to those who strayed from good.");
    eventForce( "whisper to "+keyname+" Is this burden too heavy "
      "for you? Come and ask to join if you are ready.\n");
    write("\n%^YELLOW%^When you're ready "
      "%^BOLD%^<ask to join>.%^RESET%^");

    return 1;
}

void init(){
    ::init();

}
