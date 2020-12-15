#include "messagepost.h"


MessagePost(string m, Person &p) : Post(p), message(m){

	

}

	string MessagePost::getDisplayText(){
	string ret = "MESSAGE-POST: \n";
	
	return ret;
	
	}
