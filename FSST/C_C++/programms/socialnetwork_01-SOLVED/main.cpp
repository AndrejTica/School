#include "socialnetwork.h"
#include "person.h"
#include "messagepost.h"
#include "photopost.h"

int main()
{
   SocialNetwork schoolBook;

   Person teacher1("Max", "Teacher");
   Person student1("Susi", "Student");

   schoolBook.addMember(teacher1);
   schoolBook.addMember(student1);

   MessagePost postTeacher1("What is the best coding language?", teacher1);
   MessagePost postStudent1("I like to design software!", student1);
   PhotoPost photoPostTeacher1("teacher1.jpg", teacher1);

   schoolBook.addPost(postTeacher1);
   schoolBook.addPost(postStudent1);
   schoolBook.addPost(photoPostTeacher1);

   postTeacher1.addLike();
   postTeacher1.addLike();
   postTeacher1.addLike();

   postStudent1.addLike();

   postTeacher1.addComment("Java, java, java");
   postTeacher1.addComment("I agree");
   postStudent1.addComment("software testing is coooool?");

   schoolBook.printPosts(); //diese methode ist der einzige grund wieso wir virtual verwenden. Damit wir automatisch 
   			    //den richtigen post ausgeben. 

   return 0;
}

/*
The above code gives this output:

MESSAGE-POST:
"What is the best coding language?" by Max Teacher, 3 likes
   comment: Java, java, java
   comment: I agree

MESSAGE-POST:
"I like to design software!" by Susi Student, 1 likes
   comment: software testing is coooool?

PHOTO-POST:
"teacher1.jpg" by Max Teacher, 0 likes
*/
