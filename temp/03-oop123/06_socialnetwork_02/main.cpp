#include <iostream>
using namespace std;

#include "socialnetwork.h"
#include "person.h"
#include "messagepost.h"
#include "photopost.h"

int main(){
    // Person and friends
    Person person1("Max", "Smith the I");
    Person person2("Florin", "Smith the II");
    Person person3("Chris", "Smith the III");
    Person person4("Alex", "Smith the IV");

    person1.addFriend(person2);
    person1.addFriend(person3);


    // Posts and likes and comments
    MessagePost postPerson1("What is the best coding language?", person1);
    postPerson1.addLike(person2);
    postPerson1.addLike(person3);

    postPerson1.addComment(person4, "Java,c++,c ...");
    postPerson1.addComment(person2, "I agree");


    MessagePost postPerson2("I like to design software!", person2);
    postPerson2.addLike(person1);
    postPerson2.addComment(person1, "Oh no, its hardware. Thats the best!");


    PhotoPost photoPostPerson1(person1.getSurname()+".jpg", person1);
    // ...

    // SocialNetwork
    SocialNetwork schoolBook;
    schoolBook.addMember(person1);
    schoolBook.addMember(person2);
    schoolBook.addPost(postPerson1);
    schoolBook.addPost(postPerson2);
    schoolBook.addPost(photoPostPerson1);

    // output
    schoolBook.showPersonPage(person1);
    cout << endl;
    schoolBook.showPersonPage(person2);

    cout << endl << endl;
    return 0;
}

/*
The output:
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


Lab: SocialNetwork2
Write the classes shown in the above uml diagram and test your code intensive.


Tipp:
void Person::addFriend(Person &aFriend)
{
    friends.push_back(&aFriend);
    aFriend.friends.push_back(this);
}

Tipp: create class Comment to hold the comment-text and who made the comment.

Tipp:
class Post: member likes becomes a list<Person*> to store the Person, who likes that post. The size of the ArrayList likes holds the number of likes.


*/
