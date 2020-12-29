// demo: priority_queue with pair<Node,double>
// 		 sorted by the double component
//
// see: http://www.cplusplus.com/reference/queue/priority_queue/

#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::priority_queue
#include <utility>        // std::pair
using namespace std;

// class Node holds only a string member
class Node{
	private:
		string name;
	public:
		Node(string n): name(n) {}
		string toString() const {return name;}
};


// for priority_queue to sort by the second component (double)
class cmp{
	public:
	bool operator()(pair<Node,double>& lhs, pair<Node,double>& rhs) const {
		return lhs.second < rhs.second;
	}
};

int main (){
						// typ					container						, compare
  priority_queue< pair<Node,double> , vector < pair<Node,double> > , cmp > mypq;

  Node node1("node1");
  Node node2("node2");
  Node node3("node3");

  mypq.push(make_pair(node1,10.0));
  mypq.push(make_pair(node2,900.0));
  mypq.push(make_pair(node3,30.0));

  std::cout << "mypq.top().second is now " << mypq.top().second << '\n';
  std::cout << "mypq.top().first is now " << mypq.top().first.toString() << '\n';

  return 0;
}
/*
output:
mypq.top().second is now 900
mypq.top().first is now node2

*/
