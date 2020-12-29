#include <cmath>
#include <functional>
#include <iostream>
#include <queue>   // std::priority_queue
#include <utility> // std::pair
#include <vector>

using namespace std;

// vgl: typedef pair<int,int> akge_like_t;
using age_like_t = pair<int, int>;
using distance_index_t = pair<double, int>;

#ifdef DEBUG
template <typename T> void print_queue(T q) {
  while (!q.empty()) {
    std::cout << q.top().first << " " << q.top().second << endl;
    q.pop();
  }
  std::cout << '\n';
}
#endif

vector<distance_index_t> knn(const vector<age_like_t> &data, double query,
                             int k) {

  // priority queue
  priority_queue<distance_index_t, vector<distance_index_t>,
                 std::greater<distance_index_t>>
      sorted_neighbor_distances_and_indices;

  // calc distance
  for (int i = 0; i < data.size(); i++) {
    double distance = sqrt(pow(data[i].first - query, 2.0));
    // store distance and index in poriority queue
    sorted_neighbor_distances_and_indices.push(make_pair(distance, i));
  }

#ifdef DEBUG
  print_queue(sorted_neighbor_distances_and_indices);
#endif

  // to store k elements with nearest distance to query
  vector<distance_index_t> k_nearest_distances_and_indices;
  for (int i = 0; i < k; i++) {

    distance_index_t help = sorted_neighbor_distances_and_indices.top();
    sorted_neighbor_distances_and_indices.pop();

    k_nearest_distances_and_indices.push_back(help);
  }

  return k_nearest_distances_and_indices;
}

int main() {
  int k = 3;

  /*
  #Classification Data
  #Column 0 : age
  #Column 1 : likes pineapple
  */
  vector<age_like_t> clf_data;

  clf_data.push_back(make_pair(22, 1));
  clf_data.push_back(make_pair(23, 1));
  clf_data.push_back(make_pair(21, 1));
  clf_data.push_back(make_pair(18, 1));
  clf_data.push_back(make_pair(19, 1));
  clf_data.push_back(make_pair(25, 0));
  clf_data.push_back(make_pair(27, 0));
  clf_data.push_back(make_pair(29, 0));
  clf_data.push_back(make_pair(31, 0));
  clf_data.push_back(make_pair(45, 0));

  // Question:
  // Given the data we have, does a 33 year old like pineapples on their pizza ?
  vector<distance_index_t> clf_prediction = knn(clf_data, 33, k);

  // classification uses modus of k results
  int like_yes = 0;
  int like_no = 0;

  for (int i = 0; i < k; i++) {
    int index = clf_prediction[i].second;
    if (clf_data[index].second == 0)
      like_no++;
    else
      like_yes++;
  }

  if (like_yes > like_no)
    cout << "A person with 33 years LIKES pineapple on pizzas" << endl;
  else
    cout << "A person with 33 years DOES NOT LIKE pineapple on pizzas" << endl;

  cout << endl;
  return 0;
}
