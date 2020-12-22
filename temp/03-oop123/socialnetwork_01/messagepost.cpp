#include "messagepost.h"


MessagePost::MessagePost(string m, Person& p) : Post(p), message(m){ //Post(p) is the constructor of the baseclass, we give him the person we gave to messagepost
																	 //message is just the member of messagepost subclass

}

// string Person::getMessage() const{
// 	return surname;

// }



	string MessagePost::getDisplayText(){
	string ret = "MESSAGE-POST:\n";

    ret += "\"" + message + "\" by ";
    ret += sender.getForename() + " " + sender.getSurname() + ", ";
    ret += to_string(likes) + " likes\n";

    for (auto s : comments)
        ret += "   comment: " + s + "\n";

    ret += "\n";
    
    return ret;
	
	}
