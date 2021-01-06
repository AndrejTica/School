#include "socialnetwork.h"
#include <iostream>
using namespace std;

void SocialNetwork::addMember(Person& p){
    members.push_back( &p );  
}

void SocialNetwork::addPost(Post& p){
    posts.push_back( &p );  
}




/*
// Post* p = auto p
hier kommt polymorphismus vor. Funktioniert nur mit pointern vom
typ baseclass. Der baseclasspointer p geht durch den vektor
und schaut auf welche unterklasse er zeigt. Durch virtual weiss er 
auf welches objekt er zeigt und ruft die dem entsprechende methode auf
*/
void SocialNetwork::printPosts(){ 
    // todo: 1. Meesage Posts

    for (auto p : posts){			 
        cout << p->getDisplayText();		
        					
    }						
    						

}
