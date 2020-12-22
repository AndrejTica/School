// messagepost.h

#pragma once

#include "post.h"
using namespace std;

class MessagePost : public Post { //würde private stehen, würden alle public in der baseclass private in der subclass sein
private:
	string message;
public:
	MessagePost(string m, Person &p);

	string getDisplayText() override; //


};

// ENTER CODE
