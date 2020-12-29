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


* Dijkstra uses a priority queue to store unvisited neighbours
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
#include <limits>       // std::numeric_limits
using namespace std;


#define INFINITY std::numeric_limits<double>::max()
#define UNDEFINED ""

// a Node is a string
typedef string Node;

// a Neigbour stores his distance and  name
typedef pair<double,Node> Neighbour;

// each  Node stores a list of his neighbours
typedef list<Neighbour> NeighbourList;

// Das eigentliche Netzwerk: 
// - Jedem Node ist eine Liste von Nachbarn zugeordnet
typedef map<Node,NeighbourList> AdjacencyList;


//typedef pair<double,Node> Distance_Predecessor;
//typedef map<Node,Distance_Predecessor> ResultList;

// Die Ergebnisse:
// Pro Node die geringste Distanz zum Start-Node
typedef map<Node,double> ResultDistanceList;
// Pro Node der Vorgänger-Node zum Start-Node
typedef map<Node,Node> ResultPathList;




// Die Klasse Graph speichert:
// - das Netz
// - die geringsten Entfernungen zum Start-Node
// - den unmittelbaren Vorgänger-Node Richtung Start-Node
class Graph{
private:
// Das eigentliche Netzwerk: 
// - Jedem Node ist eine Liste von Nachbarn zugeordnet
	AdjacencyList net;

// Die Ergebnisse:
// Pro Node die geringste Distanz zum Start-Node
	ResultDistanceList result_distance;
// Pro Node der Vorgänger-Node zum Start-Node
	ResultPathList result_path;
	
// Der eigntliche Algorithmus:
// - suche nächsten Nachbarn: (u genannt)
// - haben alle anderen Nachbarn (v genannt) über diesen	nächsten Nachbarn u
//			eine kürzere Distanz zum Start-Knoten ?
	void dijkstra_sssp(Node start);
	
public:
	Graph(){};
	
	void add (Node from, Node to, double distance);
	
	double get_shortest_distance(Node start, Node to);
	string get_shortest_path(Node start, Node to);
};


// for priority_queue to sort by the second component (double)
class cmp{
	public:
	bool operator()(pair<double, Node>& lhs, pair<double,Node>& rhs) const {
		return lhs.first < rhs.first;
	}
};



void Graph::add (Node from, Node to, double distance){
  // net
  Neighbour neighbour;
	neighbour.first= distance;
	neighbour.second= to;
	// = make_pair<double,Node>(distance, to);
	net[from].push_back(neighbour);
	net[to]; // ?????????????

  //result
  result_distance[from]= INFINITY;
  result_distance[to]= INFINITY;

  result_path[from]= UNDEFINED;
  result_path[to]= UNDEFINED;
}

void Graph::dijkstra_sssp(Node start){

	// Vorarbeit 1:
	// - setze jeden Knoten als unbesucht
	// - die priority_queue speichert alle noch unbesuchten Nachbarn und
	//   ist am Beginn leer
	priority_queue< Neighbour , vector < Neighbour> , cmp > neighbour_queue;

	// - setze jede Distanz af unendlich
	for (auto& p : result_distance){
		p.second= INFINITY;
	}

	// - setze jeden Vorgänger auf null
	for (auto& p : result_path){
		p.second= UNDEFINED;
	}


	// Vorarbeit 2:
	// - Setze die Distanz des Startknotens auf 0
	result_distance[start]= 0.0;
	// Setze seinen Vorgänger auf sich selbst
	result_path[start]= start;

	// setze den Startknoten in die queue, der noch unbesuchten Knoten
	Neighbour neighbour;
	neighbour.first= 0.0;
	neighbour.second= start;
	neighbour_queue.push(neighbour);

	while (! neighbour_queue.empty()){
		// hole Nachtabr mit kleinstem Abstand
		Neighbour u = neighbour_queue.top();
		neighbour_queue.pop();
    Node node_u= u.second;

		// für jeden Nachbar (v) von u
    for(auto v : net[node_u]){
      Node node_v= v.second;

      // wurde v schon einmal besucht
      if (result_distance[node_v] == INFINITY){
        // nein, also rein in die queue
        neighbour_queue.push(v);
      }

      // Berechne alternative Distanz von v über u
      double distance_from_u_to_v= v.first;
      double alternate_distance= result_distance[node_u] + distance_from_u_to_v;

      // ist von start nach v über u kürzer?
      if (alternate_distance < result_distance[node_v] ){
        result_distance[node_v]= alternate_distance;
        result_path[node_v]= node_u;
      }
    }

	}

}


double Graph::get_shortest_distance(Node start, Node to){
  this->dijkstra_sssp(start);
	return result_distance[to];
}

string Graph::get_shortest_path(Node start, Node to){
  this->dijkstra_sssp(start);
  /*
  1 S ← empty sequence
  2  u ← target
  3  if prev[u] is defined or u = source:          // Do something only if the vertex is reachable
  4      while u is defined:                       // Construct the shortest path with a stack S
  5          insert u at the beginning of S        // Push the vertex onto the stack
  6          u ← prev[u]                           // Traverse from target to source
  */

    /*
    1  Funktion erstelleKürzestenPfad(Zielknoten,vorgänger[])
      2   Weg[]:= [Zielknoten]
      3   u:= Zielknoten
      4   solange vorgänger[u] nicht null:   // Der Vorgänger des Startknotens ist null
      5       u:= vorgänger[u]
      6       füge u am Anfang von Weg[] ein
      7   return Weg[]
      */

  string path="";
  path= to;

  Node u= to;
  while (result_path[u] != UNDEFINED && u!=start){
    u= result_path[u];
    path = u + "-" +path;
  }

  return path;
}







#ifdef MAIN1
// main
// -------------------------------------------------------------
int main(){

	Graph graph;
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

				// von , nach. distanz
	graph.add("A","B", 2.0);
	graph.add("A","C", 3.0);
	graph.add("B","C", 4.0);
	graph.add("C","D", 1.0);

	// results
	double d= graph.get_shortest_distance("A","D" );
	cout << "Die kürzeste Streckenlänge von A nach D ist: " <<	d << endl;

	string path= graph.get_shortest_path("A","D" );
	cout << "Der kürzeste Weg von A nach D ist: " <<	path << endl;

	return 0;
}
#endif




#ifdef MAIN2
// main
// -------------------------------------------------------------
int main(){

	Graph graph;
/*
	Innsbruck : 100-Salzburg
	Salzburg  : 120-Linz, 200-Graz
	Graz      : 100-Wien
*/

	cout <<"                           Linz -180-Wien" <<endl;
	cout <<"                           /         /" 	<<endl;
	cout <<"                          120       /" 		<<endl;
	cout <<"                         /         /" 		<<endl;
	cout <<"Innsbruck -100- Salzburg/        100" 		<<endl;
	cout <<"                        \\        /" 			<<endl;
	cout <<"                         200    /" 			<<endl;
	cout <<"                          \\   /" 			<<endl;
	cout <<"                          Graz" 				<<endl;

				// von , nach. distanz
	graph.add("Linz","Wien",180.0);
	graph.add("Salzburg","Linz",120.0);
	graph.add("Salzburg","Graz",200.0);
	graph.add("Innsbruck","Salzburg",100.0);
	graph.add("Graz","Wien",100.0);

	// results
	double d= graph.get_shortest_distance("Innsbruck","Wien" );
	cout << "Die kürzeste Streckenlänge von Innsbruck nach Wien ist: " <<	d << endl;

	string path= graph.get_shortest_path("Innsbruck","Wien" );
	cout << "Der kürzeste Weg von Innsbruck nach Wien ist: " <<	path << endl;

	return 0;
}
#endif




#ifdef MAIN3
// main
// -------------------------------------------------------------
int main(){

	Graph graph;
// wikipedia
// https://de.wikipedia.org/wiki/Dijkstra-Algorithmus

  // von , nach. distanz
	graph.add("Frankfurt","Mannheim",  85.0);
	graph.add("Frankfurt","Würzburg",  217.0);
	graph.add("Frankfurt","Kassel",  173.0);

	graph.add("Mannheim","Karlsruhe",  80.0);

	graph.add("Würzburg","Erfurt",  186.0);
	graph.add("Würzburg","Nürnberg",  103.0);

	graph.add("Stuttgart","Nürnberg",  183.0);

	graph.add("Kassel","München",  502.0);

	graph.add("Karlsruhe","Augsburg",  250.0);

	graph.add("Nürnberg","München",  167.0);

	graph.add("Augsburg","München",  84.0);


	// results
	double d= graph.get_shortest_distance("Frankfurt","München" );
	cout << "Die kürzeste Streckenlänge von Frankfurt nach München ist: " <<	d << endl;

	string path= graph.get_shortest_path("Frankfurt","München" );
	cout << "Der kürzeste Weg von Frankfurt nach München ist: " <<	path << endl;

	return 0;
}
#endif



#ifdef BLA

/*
	graph.add("Harrisburg","Baltimore",  79.83);
	graph.add("Harrisburg","Allentown",  81.15);
	graph.add("Baltimore","Harrisburg",  79.75);
	graph.add("Baltimore","Washington",  39.42);
	graph.add("Baltimore","Philadelphia", 103.00);
	graph.add("Washington","Baltimore",  38.65);
	graph.add("Philadelphia","Baltimore", 102.53);
	graph.add("Philadelphia","Allentown",  61.44);
	graph.add("Philadelphia","New York",  96.79);
	graph.add("Binghamton","Allentown", 133.04);
	graph.add("Allentown","Harrisburg",  81.77);
	graph.add("Allentown","Philadelphia",  62.05);
	graph.add("Allentown","Binghamton", 134.47);
	graph.add("Allentown","New York",  91.63);
	graph.add("New York","Philadelphia",  97.24);
	graph.add("New York","Allentown",  87.94);
*/


	cout << graph.toString() << endl;


//SSSP
	map<Node, double> distance2Source;
	map<Node, Node> previous2Source;

	graph.dijkstraComputePaths("Frankfurt", distance2Source, previous2Source);

//	for (auto p: distance2Source){
//		cout << p.first.toString() << "->" << p.second << endl;
//	}

/////
/*
for (adjacency_map_t::iterator vertex_iter = adjacency_map.begin();
         vertex_iter != adjacency_map.end();
         vertex_iter++)
    {
        vertex_t v = vertex_iter->first;
        std::cout << "Distance to " << vertex_names[v] << ": " << min_distance[v] << std::endl;
        std::list<vertex_t> path =
            DijkstraGetShortestPathTo(v, previous);
        std::list<vertex_t>::iterator path_iter = path.begin();
        std::cout << "Path: ";
        for( ; path_iter != path.end(); path_iter++)
        {
            std::cout << vertex_names[*path_iter] << " ";
        }
        std::cout << std::endl;
    }
*/
/////

	return 0;
}


------------


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

		// add node and edges
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

#endif
