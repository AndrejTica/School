#include "post.h"


Post::Post(Person& p) : sender(p){
    //sender = p;
    likes = 0;
}

void Post::addLike(){
    likes++;
}

void Post::addComment(string m){
    comments.push_back(m);
}