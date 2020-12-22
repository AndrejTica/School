// post.h

#pragma once
#include <vector>
#include <string>
#include "person.h"
#include <iostream>
using namespace std;


class Post{
protected:					//damit unterklassen zugriff haben 
	Person& sender; //????
	int likes;
	vector<string> comments;
public:
	Post(Person& p);
	
	void addLike();
	
	void addCommments(string m);
	
	virtual string getDisplayText() = 0; //abstract method: pure virtual function, nur für unterklassen
	

};


// ENTER CODE
