#include <lib.h>
#include <daemons.h>

inherit LIB_SENTIENT;

int playerCheck();
int burnCheck();
int burnMemories();
int removeRequest();
int eventResetClass();
int generalTalk();


object *requests = ({});
int lastGreeted;
int levelcap = 25;


static void create() {

    sentient::create();

    SetKeyName("Than the Lord of Nis");
    SetId( ({"than", "than the lord of nis"}) );
    SetShort("Than the Lord of Nis");
    SetLong(
      "Before you is an old and contemplative person. "
      "It seems as the burden of the word is on its shoulders. "
      "Its skin is placid and pale. Something bothers you "
      "deeply because by appearance alone nor mannerisms "
      "can you assume its sexual identity. It seems human, "
      "yet other-worldly. It is garbed in tattered robes with "
      "a deep cowl that shadows the facial details. Its face "
      "is covered in bandages and two yellow eyes gleam back "
      "at you. \n"
      "It keeps glancinging in your direction as if it is "
      "listening to any questions asked or open conversations."
    );
    SetLevel(5);
    SetRace("human");
    SetLanguage("Common", 100);
    SetDefaultLanguage("Common");
    SetClass("wizard");
    SetGender("neuter");
    SetMorality(0);
    SetUnique(1);

    SetTalkResponses(([ 
        "default" : (:generalTalk:),
        "about" : "Are you trying ask me about something "
        "or everyone standing here?",
        "for" : "Are you trying ask me for something "
        "or everyone standing here?",
        "to" : "Are you trying ask me to do something "
        "or everyone standing here?",
        "newbie" : "You miss simplier times, eh? "
        "People remember the good but forget the bad. "
        "What if you I told you you can become one again?",
        ({"magic","magics"}) : "Youth magics? Are you interested in "
        "<ask>ing me about such things?",
        "rebuild" : "Did I hear someone mention a rebuild? I can "
        "help with such magics; just ask."
      ]));
    SetRequestResponses(([ 
        "default" : "For what?",
        ({"help","information","info"}) : 
        "I can burn away your recent experiences "
        "and set you back to being a newborn, well, to "
        "some extent. It's called a memory burn.",
        ({"memory burn","burn","rebuild"}) : "I truely hope you "
        "are not just asking for a burn without finding "
        "out about one. Ignorant descisions and "
        "permnament effects do not mix well. \n"
        "If you understand what it is all about you can "
        "<ask [me] to burn memories> away you wish forgotten."
      ]));
    SetConsultResponses( ([
        "default" : "About what?",
        ({"memory burn","burn", "magic","magics","youth magics"}) : 
        "Yes, I can help you with this. Remember this is a one way "
        "trip. With a memory burn you cannot be restored to your "
        "current status but instead have to rebuild. If this is what "
        "ou want then ask me to do it."
      ]) );
    SetCommandResponses( ([
        "default" : "Do what? "
        "(format: %^CYAN%^BOLD%^<ask [me] to proceed>%^RESET%^)",
        ({"burn","burn memories","proceed"}) : (:burnCheck:)
      ]) );
}

void init(){

    ::init();

    if(lastGreeted<time()){
        lastGreeted = time() + random(300);
        call_out("playerCheck", 2);
    }

}

int playerCheck(){

    object *invPlayers = ({});
    object *newbs = ({});
    object me;

    if(!environment()||!clonep(me = this_object()) )return 0;
    foreach(object p in all_inventory(environment())){
        if(userp(p) && !p->GetInvis()) invPlayers = invPlayers + ({p});
        if(newbiep(p) && !p->GetInvis()) newbs = newbs + ({p});
    }	

    switch(sizeof(invPlayers)){
    case 0 : return 1;
    case 1 :
        eventForce("say Hello, "+invPlayers[0]->GetCapName()+".");
        return 1;
    case 2 :
        eventForce("say Hello "+invPlayers[0]->GetCapName()+" and "
          +invPlayers[1]->GetCapName()+".");
        return 1;
    case 3 :
        eventForce("say Hello, "+invPlayers[0]->GetCapName()+", "
          +invPlayers[1]->GetCapName()+", and "+invPlayers[2]->GetCapName()+".");
        return 1;

    default: eventForce("say Hello, all.");	
    }

    if(sizeof(newbs)){
        eventForce( "say Ah, to be young newbie again. I used to work magics of "
          "youth but I finally accepted my old age.");
    }

    return 1;
}


int burnCheck(object you, object me, string str){


    if(you->GetClass()=="explorer"){
        eventForce("emote shakes his head.");
        eventForce("say Enjoy being an explorer for now.");
        return 1;
    };



    if(member_array(you, requests) != -1 ){
        eventForce("say Hold on a dang minute. Impatient children!");
        return 1;
    }

    requests = requests + ({ you });
    input_to("burnMemories");
    eventForce("shrug"); 

    call_out("removeRequest", 30, you );	

    message("my_action",
      you->GetCapName()+", are you sure you want to do this?.\n"
      "%^BOLD%^Enter: %^RED%^Y or N%^RESET%^", you);


    return 1;
}

int removeRequest(object you){

    if(member_array(you, requests) != -1){
        if(you) message("other_action", "Memory Burn: Request for class reset timed out.", you );
        requests = requests - ({ you });
    }

    return 1;
}

burnMemories(string str){

    object tp = this_player();
    string name = tp->GetCapName();
    str = lower_case(str);
    requests = requests - ({ tp });

    if(str == "y"||str == "yes"){
        eventForce("shout I warned you, "+name+"!");
        message("my_action",
          "\n%^GREEN%^BOLD%^"+
          GetCapName()+" grabs each side of your temple, "
          "eyes glowing with blue flames. \n%^CYAN%^"+
          capitalize(nominative(this_object()))+
          " sears you with arcane powers as your head throbs "
          "and lose yourself in a scream. %^RESET%^", 
          tp);
        message("other_action",
          "%^GREEN%^BOLD%^"+GetCapName()+" grabs "+name+
          ", eyes afire with blue arcane energy. \n%^CYAN%^"+
          name+" screams in agony! %^RESET%^",
          environment(), tp);

        eventResetClass(tp);

        return 1;
    }

    message("my_action",
      this_player()->GetCapName()+", I'm glad you reconsidered. "
      "Find me if you change your mind.", 
      this_player());
    return 1;
}

int eventResetClass(object tp){

    int points = tp->GetExperiencePoints();
    int level = tp->GetLevel();

    tp->AddExperiencePoints( -points );    

    /*
if(GetClass() == "explorer"){
        foreach(cl in GetSkills()){
            RemoveSkill(cl);
//addtrainingpoints?
*/

    tp->ChangeClass("explorer");

    if(level>1){

        if(level>levelcap) level = levelcap;

        points = PLAYERS_D->GetLevelList()[level]["xp"];

        tp->ChangeLevel(1);
        tp->AddExperiencePoints(points);

        foreach(string ptitle in tp->GetTitles()) 
            tp->RemoveTitle(ptitle);

        message("my_action",
          "You have been awarded "+points+" experience points.\n", 
          tp);
    }

    return 1;
}

int generalTalk(object tp, object to, string str, string lang){

    string *eavesdrop = ({
      "emote listens closely.",
      "emote looks at "+tp->GetCapName()+" thoughtfully.",
      "emote wonders if "+tp->GetCapName()+
      " is getting bored of being "+add_article(tp->GetClass())+
      " yet.",
      "grin ev",
      "emote mumbles about mastering youth magics and the "
      "pointlessness of it all.",
      "emote scratches his head, puzzled."
    });

    int r = random(sizeof(eavesdrop));

    if(random(100) >30) eventForce( eavesdrop[r] );

    return 1;
}
