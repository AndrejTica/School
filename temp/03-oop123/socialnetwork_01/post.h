// post.h

#pragma once
#include <vector>
using namespace std;


class Post{
protected:
	Person& sender; //????
	int likes;
	vector<string> comments;
public:
	Post(Person& p);
	
	void addLike();
	
	void addCommments(string m);
	
	virtual string getDisplayText() = 0; //abstract method: pure virtual function
	

};


// ENTER CODE
