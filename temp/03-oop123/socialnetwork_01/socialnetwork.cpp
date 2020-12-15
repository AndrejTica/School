#include "socialnetwork.h"

void SocialNetwork::addMember(Person& p){
	members.push_back(&p); //address operator

}

void addPost(Post &p){
	posts.push_back(&p);

}

void SocialNetwork::printPosts(){

	for (auto p : posts){
	cout << p->getDisplayText();
	
	}
	cout << "TODO" <<endl;

}
