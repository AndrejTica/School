// socialnetwork.h
#pragma once
#include <vector>
#include "person.h"
#include "post.h"
using namespace std;

class SocialNetwork{

private:
	vector<Person *> members;
	vector<Post*> posts;
	
public:
	SocialNetwork(){}

	void addMember(Person& p); //damit nicht kopiert wird. Bei objekt übergabe sehr wichtig für die schnelligkeit 
	void addPost(Post &p);
	void printPosts();
	
};

// ENTER CODE
