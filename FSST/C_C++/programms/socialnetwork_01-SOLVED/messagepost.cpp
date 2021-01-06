#include "messagepost.h"

MessagePost::MessagePost(string m, Person & p) 
: Post(p) , message(m){

    //message = m;
}

string MessagePost::getDisplayText() {
    string ret = "MESSAGE-POST:\n";

    ret += "\"" + message + "\" by ";
    ret += sender.getForename() + " " + sender.getSurname() + ", ";
    ret += to_string(likes) + " likes\n";

    for (auto s : comments)
        ret += "   comment: " + s + "\n";

    ret += "\n";
    
    return ret;

}  // überschreiben
