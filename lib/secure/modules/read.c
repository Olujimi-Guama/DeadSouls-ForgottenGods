#include <lib.h>
#include <modules.h>
string globalstr, globalstr2, globalstr3;

varargs string ReadMatchingLine(string target, string substring, string exclude){
    int omit, done, tail_search, i;
    string contents, line, filename, new_file;
    globalstr = "";
    globalstr2 = "";
    globalstr3 = "";

    if(!target || !file_exists(target)) true();
    else target = read_file(target);
    if(!target) return "";
    if(strsrch(target,substring) == -1) return "";
    if(strsrch(target,"\n") == -1) return "";
    filename = generate_tmp(this_object());
    new_file = "";
    if(!exclude) exclude = filename;

    write_file(filename,target);


    omit = 1;
    for(i=1; !done; i++){
	line = read_file(filename, i, 1);
	if(!line) break;
	if(grepp(line,substring) ) {
	    omit =0;
	}
	if(!omit && truncate(last(line,2,1),1) != ";") {
	    tail_search = 1;
	}
	else {
	    tail_search = 0;
	}

	if(!omit) {
	    new_file += line;
	}

	if(!tail_search) omit = 1;
	if(!line) done = 100;
	if(i == 999) done = 100;
    }

    rm(filename);
    return new_file;
}

mapping eventParsePair(string file, string param, string type, string mode){
    mixed val, key;
    string func, junk;
    int tempint;
    mapping RetMap = ([]);
    string line = this_object()->ReadMatchingLine(file, param);
    sscanf(line,"%s(%s,%s);%s",func,key,val,junk);
    if(!key || !val) {
	return ([]);
    }
    if(sscanf(val,"%d",tempint) && !alphap(val)) val = tempint;
    key = this_object()->eventCleanString(key);
    if(stringp(val)) val = this_object()->eventCleanString(val);
    RetMap[key] = val;
    return RetMap;
} 

string eventCleanString(string str){
    str = replace_string(str,"\n","");
    str = replace_string(str,"\t","");
    str = replace_string(str,"\"","");
    str = space_trim(str);
    str = trim(str);
    return str;
}

mapping eventMappifyLine(string file, string param){
    mixed RetMap;
    string schmutz;

    schmutz = this_object()->ReadMatchingLine(file, param);
    if(!grepp(schmutz,param)) return ([]);
    schmutz = this_object()->eventExtractMapString(schmutz);
    schmutz = replace_string(schmutz,"\n","");
    schmutz = replace_string(schmutz,"\t","");
    schmutz = replace_string(schmutz," : ",":");
    schmutz = space_trim(schmutz);
    schmutz = replace_string(schmutz,", \"",",\"");
    schmutz = trim(schmutz);
    if(last(schmutz,1) != ","){
	schmutz = "(["+schmutz+",])";
    }
    else schmutz = "(["+schmutz+"])";
    RetMap = restore_variable(schmutz);
    if(!mapp(RetMap)){
	write("Mappification unsuccessful.");
	return ([]);
    }
    else return RetMap;
}

string eventExtractMapString(string str){
    string meat, junk1, junk2;
    str = replace_string(str,"[","OPENBRACKET",1);
    str = reverse_string(replace_string(reverse_string(str),"]","TEKCARBESOLC",1));
    sscanf(str,"%sOPENBRACKET%sCLOSEBRACKET%s",junk1,meat,junk2);
    return meat;
}
