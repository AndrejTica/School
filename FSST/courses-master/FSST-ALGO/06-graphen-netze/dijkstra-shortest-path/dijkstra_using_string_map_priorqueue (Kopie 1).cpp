/** Dijkstra - Algorithm: cpp using a priority queue

@file dijkstra_using_string_map_priorqueue.cpp

* g++ -std=c++11 dijkstra_using_string_map_priorqueue.cpp -o dijkstra_using_string_map_priorqueue.exe
* ./dijkstra_using_string_map_priorqueue.exe

@description
classes:
* class Node
- Nodes are names(string)
- A Node uses a list of Edges to store its neighbour nodes.

* class Edge
- distance (integer, the distance to the neighbour node)
- node (the name of the neighbour node)

* class Graph
- Adjacency-List, which is a map that holds for a node a list of 
	 		Edges to the neighbours


* Dijkstra uses a priority queue to store the unvisited neighbours
* Dijkstra uses a map to store the shortest distance of a Node to the source
* Dijkstra uses a map to store the previous node of a Node to get the path from source to target


@example
	A : B-2 , C-3
	B : C-4
	C : D-1
	D :

  A --2-- B
  |       |
  |       4
  |       |
  + --3-- C --1-- D

  graph.add("A","B", 2);
  graph.add("A","C", 3);
  graph.add("B","C", 4);
  graph.add("C","D", 1);

@see
- http://www.cplusplus.com/reference/queue/priority_queue/ 
*/

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <limits>       // std::numeric_limits
using namespace std;


class Edge{
	private:
		string node;     // is a neighbour
		int distance;
	public:
		Edge(string n, int d): node(n), distance(d){}
		
		string getNode(){return node;}
		int getDistance(){return distance;}

		string toString(){
			ostringstream os;
			os << node << "-" << distance;
			return os.str();
		}
};


// for priority_queue to sort by the second component
class cmp{
	public:
	bool operator()(pair<int,string>& lhs, pair<int,string>& rhs) const {
		return lhs.first < rhs.first;
	}
};

class Graph {
	private:
		// node and a list of Edges to the neighbours
		map<string, list<Edge*> > adjList; 
				
	/*
		A : B-2 , C-3
		B : C-4
		C : D-1
		D :

	  A --2-- B
	  |       |
	  |       4
	  |       |
	  + --3-- C --1-- D

	  graph.add("A","B", 2);
	  graph.add("A","C", 3);
	  graph.add("B","C", 4);
	  graph.add("C","D", 1);
	*/


		// for dijkstra
		// each node has a shortest disctance to the source node
		map<string,int> distance2Source;

		// each node has its previous node to get the path to source
		map<string,string> previousNode2Source;

	public:
		Graph(){
			//todo
		}

		// add node an edges
		void add(string node1, string node2, int dist){
			adjList[node1].push_back(new Edge(node2,dist));
			adjList[node2];
		}


		// get the distance from -> to
		int getDistance(string from, string to){
			
			for (auto pEdge : adjList[from]){
				if (pEdge->getNode() == to)
					return pEdge->getDistance();
			}
			// todo exception: from has no neighbour with name to
			return -1000;
		}
		

		/*
		Init:
			setze jeden Knoten als unbesucht
			setze jede Distanz auf unendlich
			setze jeden Vorgänger auf null

			setze die Distanz des Startknoten auf 0
			setze seinen Vorgänger auf sich selbst.


		Algo:
		Wiederhole bis alle Knoten besucht sind
			setze den unbesuchten Knoten mit der gerinsten Distanz als aktuell und besucht
			für alle unbesuchten Nachbarn: addiere eigene Distanz und das Kantengewicht
				wenn Summe geringer ist als deren aktuellen Distanz
					dann setze sie 
					und setze dich als seinen Vorgänger

		*/
		/*
		DIJKSTRA(G, s, w)
		  d[s] := 0 
		  INSERT(Q, s)
		  while (Q != Ø)
			u := EXTRACT-MIN(Q)
			for each vertex v in Adj[u]
			  if (w(u,v) + d[u] < d[v])
				d[v] := w(u,v) + d[u]
				p[v] := u 
				if (d[v] was originally infinity) 
				  INSERT(Q, v)   
				else
				  DECREASE-KEY(Q, v)
			  else
				...
			end for
		  end while
		  return (d, p)
		*/

		// THE DIJKSTRA ALGORITHM: single source shortest path

		void dijkstra(string startNode){
		// init
			for (auto pm : adjList){
					distance2Source[pm.first]= numeric_limits<int>::max();
					previousNode2Source[pm.first]= "";		
			}

			distance2Source[startNode]= 0;
			previousNode2Source[startNode]= startNode;		



		//
			priority_queue< pair<int,string> , vector < pair<int,string> > , cmp > q;
			string currentNode= startNode;
		 
			q.push(make_pair(distance2Source[currentNode],currentNode));
			while( ! q.empty()){

				string currentNode= q.top().second;
				q.pop();
				cout << "currentNode= " << currentNode << endl;

				// for each neighbour of currentNode
				for (auto p_edge : adjList[currentNode]){
					int dist= distance2Source[currentNode] + p_edge->getDistance();
					cout << "... currentNode= "<< currentNode <<endl;
					cout << "... neighbour= "<< p_edge->getNode() <<endl;
					cout << "... dist= " << dist <<endl;
					cout << "... dist to neighbour= " << p_edge->getDistance() <<endl;
					cout << "... dist OF neighbour= " << distance2Source[p_edge->getNode()] <<endl;


					if (dist < distance2Source[p_edge->getNode()]){
						cout << "... neue Distanz für " << p_edge->getNode() << endl;
						int beforeDistance= distance2Source[p_edge->getNode()];
						distance2Source[p_edge->getNode()]= dist;
						previousNode2Source[p_edge->getNode()]= currentNode;		

						if (beforeDistance == numeric_limits<int>::max()){
							q.push(make_pair(distance2Source[p_edge->getNode()],p_edge->getNode()));
						}else{
							// remove p_edge->getNode() from q
							
						}
						

					}
						
				}


			}
		}





		// print the route from->to
		// precondition: dijkstra() has to be called first
		void print_route(string from, string to){

			if (previousNode2Source[from]==to && distance2Source[from]==0){
				return;
			}
			else{

				print_route(previousNode2Source[from],previousNode2Source[to]);
				
				cout << "   from= " <<previousNode2Source[to];
				cout << " ---> "<< getDistance(previousNode2Source[to], to) << " km ---> " << " to= " <<to  <<endl;
				
			}
		}

		// prints all information
		// can be used to get an overview of the algorithm
		void print_dijkstra(string from, string to){

		// graph:
			cout << endl;
			cout << "*******************************************" << endl;
			cout <<" Graph: FROM " << from << " TO " << to << " ...." <<endl;
			cout << "*******************************************" << endl;
			
			cout << endl<< "1. Shortest distance: FROM " << from << " TO " << to <<endl;
			cout << "   " << from << " ----> " << distance2Source[to] << " -----> " << to << endl;


			cout << endl<< "2. Route with shortest distance FROM " << from << " TO " << to <<endl;
			print_route(from,to);

			cout << endl<< "3. The Graph ..." <<endl;
			print();

			cout << endl;

			cout << "previous ..." << endl;
			for (auto p : previousNode2Source){
		//		cout << p.second << " <- ist Vorgänger von " << p.first << endl;
				cout << "prev[" <<p.first << "]= " << p.second << endl;
			}
			
			cout << endl;
			cout << "dist to A ..." << endl;
			for (auto p : distance2Source){
				cout << "dist[" <<p.first << "]= " << p.second << endl;
			}
		}



		// print the graph
		void print(){
			for (auto pm : adjList){
				cout << endl << "   " << pm.first<< "\t: ";
					for( auto pl : pm.second){
						cout << pl->toString() << " , ";					
					}
			}
			cout << endl;
		}


		~Graph(){

			//todo
		}
};



int main() {
/*
		A : B-2 , C-3
		B : C-4
		C : D-1
		D :

	  A --2-- B
	  |       |
	  |       4
	  |       |
	  + --3-- C --1-- D
*/


cout << "A --2-- B" <<endl;
cout << "|       |" << endl;
cout << "|       4" << endl;
cout << "|       |" << endl;
cout << "+ --3-- C --1-- D" << endl;

	Graph graph;

	graph.add("A","B", 2);
	graph.add("A","C", 3);
	graph.add("B","C", 4);
	graph.add("C","D", 1);

	graph.dijkstra("A");

	graph.print_dijkstra("A", "D");


	return 0;
}

