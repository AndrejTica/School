#include "socialnetwork.h"

void SocialNetwork::showPersonPage( Person &p)
{
    string ret="";

    ret+= "PAGE of " + p.toString() + "\n";
    ret+= "====================================================\n";
    ret+= "Friends:\n";
 
	// ENTER CODE

	ret+= "Posts:\n";

	// ENTER CODE
    
	cout << ret << endl;
}

/*
    PAGE of Max Smith the I
    =============================================================
    Friends:
       Chris Smith the III
       Florin Smith the II
    Posts:
       MESSAGE-POST: "What is the best coding language?" by Max Smith the I, 2 likes
          comment: Java,c++,c ... (Alex Smith the IV)
          comment: I agree (Florin Smith the II)

       PHOTO-POST: "Smith the I.jpg" by Max Smith the I, 0 likes


    PAGE of Florin Smith the II
    =============================================================
    Friends:
       Max Smith the I
    Posts:
       MESSAGE-POST: "I like to design software!" by Florin Smith the II, 1 likes
          comment: Oh no, its hardware. Thats the best! (Max Smith the I)

*/

//
//    for (auto member: members){
//        ret+= "PAGE of " + member->toString() + "\n";
//        ret+= "====================================================\n";
//        ret+= "Friends:\n";

//    }
