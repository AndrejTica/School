// socialnetwork.h
#pragma once
#include <vector>
#include "person.h"
using namespace std;

class SocialNetwork{

private:
	vector<Person *> members;
	vector<Post *> posts;
	
public:
	SocialNetwork(){}

	void addMember(Person& p); //damit nicht kopiert wird
	void addPost(Post &p);
	void printPosts();
	
}

// ENTER CODE
