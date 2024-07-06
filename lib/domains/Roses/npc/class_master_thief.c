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

    if(who->GetClass() == "thief") return 1;

    if(wizardp(who)){
        write(GetName()+" is oblivious to your presence.");	
        return 1;
    }

    return ::AllowPass(who, what);
}

int CheckVisitor(object who){

    eventForce("shake");
    eventForce("say Sorry friend, only those of the brotherhood "
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

    eventForce("thief %^B_BLUE%^WHITE%^BOLD%^"+
      "HELP! I'm being attacked by "+implode(assailant, ", ")+
      "!%^RESET%^");
}



static void create() {
    trainer::create();

    SetKeyName("Master Thief Reichsacht");
    SetId("reichsacht", "trainer", "thief");
    SetShort("Master Thief Reichsacht the Dastardly Bastard");
    SetLong(
      "Before you stands a tall lean man with pale olive skin "
      "and jagged scars across his face. He keeps a vilgilant "
      "watch over the accessable entrance to the curious and "
      "lost. His dark robes common in his profession masks his "
      "outline and movements. Within the shadow of his hood "
      "all that can be seen is his sinister grin and white locks "
      "of hair cascading down from his shoulders. \n"

      "\nReichsacht initiates new members into the ways of "
      "the town's collective thieves, rogues, assasins, and "
      "all underhanded and otherwise unsavory professions. \n"
      "If you are considering following thier path, you can "
      "%^CYAN%^BOLD%^<ask Reichsacht for help>%^RESET%^."
    );
    SetRace("noor");
    SetClass("thief");
    SetLevel(45);
    SetGender("male");
    SetMorality(-400);
    SetProperty("no bump", 1);
    SetGuard("west", (: CheckVisitor :));
    SetLanguage("Common", 100);
    SetDefaultLanguage("Common");
    SetNoSpells(1);
    SetCombatAction(100, (: combatHelp :));
    AddTrainingSkills(({
        "blade attack","blade defense","knife attack","knife defense"
      }));
    // stick him on the fighter line
    if( clonep() ) {
        AddChannel("thief");
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

    if(ob->GetClass() != "thief") {
        eventForce("say Did you come all this way to ask me about being a thief?");

        if(ob->GetClass() != "explorer") {
            eventForce("say I'm afraid you've wasted your time.");
            eventForce("say It's a well known fact that anyone studied in "
              +capitalize(ob->GetClass())+" arts would make a pathetic thief.");
            return 1;
        }

        eventForce("say Well, you can ask to preview thief if you're interested.");	
        return 1;
    }
    return 1;
}

int JoinGuild(object ob, string verb, string what){
    string keyname = ob->GetKeyName();
    string name = ob->GetName();
    if(ob->GetClass() == "thief") {
        eventForce("say How mant times you think you can become a thief?");

        return 1;
    }
    eventForce("say Hmm...want to join our brotherhood, do you?");

    if(ob->GetClass() == "explorer" || !ob->GetClass()){
        eventForce("say very well, "+ob->GetName()+".");
        write("The Master Thief initiates you into the class of thieves.");
        write(this_player()->query_cap_name()+" becomes a thief.", ob);
        this_player()->ChangeClass("thief");
        this_player()->init_skills("thief");
        this_player()->SetLoginSite( MY_ROOM "/classhall_thief" );
        this_player()->AddTitle("the clumsy cut-purse");

        eventForce("say Welcome to the brotherhood!");
        eventForce("laugh");
        eventForce("say You can come to me for training when ready. "
          "And stop uncovering the damn rubble... use the bloody west "
          "entrance like a respectable member of the brotherhood.");
        return 1;
    }
    eventForce("say A "+capitalize(ob->GetClass())+" trying to learn the "
      "ways of a thief? Might as well put a dress on a bull and take it dancing!");
    eventForce("say I'm sorry, friend. It looks to me like you have already "
      "chosen your path. Last thing we need is to stir up problems with the "
      +capitalize(ob->GetClass())+"'s Guild.");
    return 1;
}

int PreviewGuild(object ob, string verb, string what){
    string keyname = ob->GetKeyName();
    string name = ob->GetName();

    if(ob->GetClass() == "thief") {

        eventForce("say Seriously? Grab a knife and stick the business end into "
          "someone!");
        return 1;
    }

    if(ob->query_class() != "explorer") {
        eventForce("say You've chosen a diifferent path, "+name+
          ", go follow it.");
        return 1;
    }

    say(name+" asks about joining the brotherhood.",
      ob);

    eventForce("laugh w");
    eventForce( "whisper to "+keyname+" "
      "Thieves, bandits, con-artists, cut-purse, cut-throats, "
      "assassins-- all have different motives, methods, "
      "and techniques. What they do share is willingness "
      "to operate on the moral shady road. With their mastery of "
      "subterfuge methods and stealth, rogues are "
      "agents of the shadows, striking unseen, pinpointing "
      "weaknesses to be exploited, and retreating before "
      "the treat of retaliation culminates into "
      "irreversible losses." );
    eventForce( "whisper to "+keyname+" "
      "These dark agents are employed by "
      "the same society that condemns them; to force action where "
      "politics fail. This is the life you will live, "
      "if so you choose. The stalker and the hunted. "
      "If you are ready to leave the simple life for "
      "such of one filled with risks and dangers " );
    eventForce( "emote eyes the room suspiciously before continuing..." );
    eventForce( "whisper to "+keyname+" "
      "Look, little "+(ob->GetGender()=="male"?"boy":"one")+
      " this isn't a cakewalk. It's not easy and worst there's no cake! "
      "But you have that fire in your eyes like you determined to make "
      "something of yourself. Fine.");
    eventForce( "whisper to "+keyname+" "
      "You ready to do this, then just pull up your short hairs "
      "and ask me to join.");
    write("\n%^YELLOW%^When you're ready %^BOLD%^<ask reichsacht to join>.%^RESET%^");

    return 1;
}

void init(){
    ::init();

}

