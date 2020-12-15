// messagepost.h

#pragma once

#include "post.h"
using namespace std;

class MessagepPost : public Post {
private:
	string message;
public:
	MessagePost(string m, Person &p);

	string getDisplayText(); //


}

// ENTER CODE
