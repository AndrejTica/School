// socialnetwork.h
#pragma once
#include "person.h"
#include "post.h"


#include <vector>
using namespace std;

class SocialNetwork{
private:
    vector<Person *> members;
    vector<Post *> posts;

/* 
bei abstrakten klassen muessen wir pointer von den objeken speichern in ein vektor. Ein vektor kopiert auch objekte in sich hinein
wir können keine referenzen an vectoren übergeben, deswegen pointer. Ein vector kopiert deswegen, weil die objekte genau wie variablen nach
deklaration irgendwo im speicher sind, sie sind nicht neben einander von anfang an. Damit der vektor alle elemente nebeneinander hat 
muss er sie also kopieren, das geht bei abstrakten klassen nicht. Deswegen speichern wir die pointer neben einanader ein. 
pointer vectoren erlauben uns also polymorphismus zu benutzen, weil wir ja dann das problem von abstrakte instanz erzeugen nicht haben
*/ 

public:
    SocialNetwork(){}
    //Bei Person muss es keine referenz sein weil person keine abstrackte klasse ist, aber machen es trotzdem wegen speicher

    void addMember(Person& p);  // referenz vgl. and. name
    //wenn wir objekte an funktionen übergeben, wird da eine neue instanz nur für diese funktion erstelt
    //mit referenz objekten können wir verhindern das ein neuer objekt instanziert wird (kopiert)
    void addPost(Post &p);

    void printPosts();
};
