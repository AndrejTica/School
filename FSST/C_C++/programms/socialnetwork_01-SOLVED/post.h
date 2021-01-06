// post.h

#pragma once

#include "person.h"
#include <vector>
using namespace std;

class Post{
protected:
    Person& sender; // ?????
    int likes;
    vector<string> comments;
public:
    Post(Person& p); // ?????

    void addLike();

    void addComment(string m);

    virtual string getDisplayText() = 0 ;  // abstrakte Methode: pure virtual function
};
