// messagepost.h

#pragma once

#include "post.h"

class MessagePost : public Post{
private:
    string message;
public:
    MessagePost(string m, Person & p);

    string getDisplayText() override;  // überschreiben

};
