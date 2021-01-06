#include "photopost.h"

PhotoPost::PhotoPost(string s, Person &p)
    : Post(p), filename(s) {}

string PhotoPost::getDisplayText()
{
    string ret = "PHOTO-POST:\n";

    ret += "\"" + filename + "\" by ";
    ret += sender.getForename() + " " + sender.getSurname() + ", ";
    ret += to_string(likes) + " likes\n";

    for (auto s : comments)
        ret += "   comment: " + s + "\n";

    ret += "\n";

    return ret;
}
