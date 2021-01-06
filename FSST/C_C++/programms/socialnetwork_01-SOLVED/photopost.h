#pragma once

#include "post.h"
#include <string>
using namespace std;

class PhotoPost : public Post{
  private:
	string filename;

  public:
	  PhotoPost(string s, Person &p);

	  string getDisplayText() override;	  
};
