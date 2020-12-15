#include <iostream>
#include <vector>

using namespace std;

//there is a function in std called vector, which is made from templates. it should be called array list because that makes lot more sense
//you dont give it a size because its dynamic
//it works like this: whenever you reach over the size, a new vector with more memory gets created, it gets copied into that one, and the old one gets deleted


struct Vertex
{
    float x, y, z;
};

ostream& operator<<(ostream& o, const Vertex& vertex){
    o << vertex.x << "," << vertex.y << "," << vertex.z;
    return o;

}

int main()
{
   vector<Vertex> vertices;
   vertices.push_back({1,2,3}); //adding an element
   vertices.push_back({4,5,6});
   //now lets go through all of them and print them

   for (int i=0; i < vertices.size(); i++) //size from vector class
    cout << vertices[i]<<endl;              //in vector the index operator is already overloaded to be able to print like this

   for(Vertex& v : vertices)    //the same thing as above, just need a reference to avoid copying
    cout << v << endl;

    vertices.clear(); //clear the whole array, set it back to zero

   // vertices.erase(vertices.begin() + 1); //this erases second element, cant just put 2 inside

    for(Vertex& v : vertices)    //the same thing as above, just need a reference to avoid copying
    cout << v << endl;

}