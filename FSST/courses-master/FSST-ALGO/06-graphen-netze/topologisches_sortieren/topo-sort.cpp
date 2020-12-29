#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

class TopoSort {
private:
  list<string> node_list;
  map<string, list<string>> successor_list;
  map<string, int> predecessor_count_list;
public:
  TopoSort();
  void add(string predecessor, string successor);
  void print_successor_list();
  void print_predecessor_count_list();
  void topo_sort();
};

TopoSort::TopoSort() {}

void TopoSort::add(string predecessor, string successor) {
  // update node_list
  node_list.push_back(predecessor);
  node_list.push_back(successor);

  node_list.unique();
  node_list.sort();

  // update successor_list
  successor_list[predecessor].push_back(successor);
}

void TopoSort::print_successor_list() {
  cout << endl<<"*** succesor list ***" << endl;

  for (auto &prev : successor_list) {
    cout << prev.first << ":";
    for (auto &succ : prev.second) {
      cout << succ << ",";
    }
    cout << endl;
  }
}

void TopoSort::print_predecessor_count_list() {
  cout << endl<<"*** predecessor_count_list ***" << endl;

  for (auto &p : predecessor_count_list) {
    cout << p.first << ":" << p.second << endl;
  }
}

void TopoSort::topo_sort() {
  // init predecessor_count_list
  for (auto &node : node_list) {

    // if node exists in successor_list.second -> counter++
    predecessor_count_list[node] = 0;
    for (auto &p : successor_list) {
      list<string>::iterator it;
      it = find(p.second.begin(), p.second.end(), node);
      if (it != p.second.end()) // found
        predecessor_count_list[node]++;
    }
  }

  print_predecessor_count_list();
  // cout << endl << __LINE__ << endl;

  list<string> help_to_decrement;
  list<string> help_to_delete;
  while (!predecessor_count_list.empty()) {
    print_predecessor_count_list();
    //    cout << endl << __LINE__ << endl;

    help_to_delete.clear();
    help_to_decrement.clear();
    // output all nodes that have no predecessor
    for (auto &p : predecessor_count_list) {
      if (p.second == 0) {
        //      cout << endl << __LINE__ << endl;
        cout << p.first << ",";

        // mark it
        help_to_delete.push_back(p.first);

        // update list with nodes that have to decr.
        // 1. look for successors of p.first
        // 2. decr these successors
        for (auto &succ : successor_list[p.first]) {
          help_to_decrement.push_back(succ);
        }
      }
    }

    // delete marked elements
    for (auto &p : help_to_delete)
      predecessor_count_list.erase(p);

    // decrement successors
    for (auto &p : help_to_decrement)
      predecessor_count_list[p]--;
  }
}

int main() {
  TopoSort topo;

  topo.add("Unterhemd", "Pullover");
  topo.add("Unterhose", "Hose");
  topo.add("Pullover", "Mantel");
  topo.add("Hose", "Mantel");
  topo.add("Hose", "Schuhe");
  topo.add("Socken", "Schuhe");

  topo.print_successor_list();

  topo.topo_sort();

  cout << endl;
  return 0;
}
