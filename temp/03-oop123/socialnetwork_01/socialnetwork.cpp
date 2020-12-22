#include "socialnetwork.h"
#include <iostream>
using namespace std;

void SocialNetwork::addMember(Person& p){
	members.push_back(&p); //address operator weil vector ja adressen speichert 

}
 
void SocialNetwork::addPost(Post &p){
	posts.push_back(&p);

}

void SocialNetwork::printPosts(){

	for (auto p : posts){
	cout << p->getDisplayText();
	
	}
	cout << "TODO" <<endl;

}
