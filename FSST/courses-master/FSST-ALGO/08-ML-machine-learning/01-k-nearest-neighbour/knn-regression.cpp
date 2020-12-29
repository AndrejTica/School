// knn-regression.cpp
//
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>   // std::priority_queue
#include <utility> // std::pair
#include <vector>
using namespace std;

// vgl: typedef pair<double,int> distance_index_t;
using distance_index_t = pair<double, int>;
using height_weight_t = pair<double, int>;

#ifdef DEBUG
template <typename T> void print_queue(T q) {
  while (!q.empty()) {
    std::cout << q.top().first << " " << q.top().second << endl;
    q.pop();
  }
  std::cout << '\n';
}
#endif

/**
 KNN - ALGO
 */
vector<distance_index_t> knn(const vector<height_weight_t> &data, double query,
                             int k) {

  // priority queue stores
  // all examples in form of:
  // distance of feature to query and index of feature
  priority_queue<distance_index_t, vector<distance_index_t>,
                 std::greater<distance_index_t>>
      sorted_neighbor_distances_and_indices;

  for (int i = 0; i < data.size(); i++) {
    // calc distance
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
  vector<height_weight_t> reg_data;
  int k = 3;

  /*
  # Example 1: Regression Data
  # Column 0: height (inches)
  # Column 1: weight (pounds)
  */
  reg_data.push_back(make_pair(167.00, 51.25));
  reg_data.push_back(make_pair(181.66, 61.91));
  reg_data.push_back(make_pair(176.28, 69.41));
  reg_data.push_back(make_pair(173.28, 64.56));
  reg_data.push_back(make_pair(172.19, 65.45));
  reg_data.push_back(make_pair(174.50, 55.93));
  reg_data.push_back(make_pair(177.29, 64.18));
  reg_data.push_back(make_pair(177.83, 61.90));
  reg_data.push_back(make_pair(172.47, 50.97));
  reg_data.push_back(make_pair(168.88, 57.81));

  // Question:
  // Given the data we have, what's the best-guess at someone's weight if they
  // are 152.4 cm tall?
  vector<distance_index_t> reg_prediction = knn(reg_data, 152.4, k);

  // Regression uses mean of k results
  double best_guess = 0.0;
  for (int i = 0; i < k; i++) {
    int index = reg_prediction[i].second;
    best_guess += reg_data[index].second;
  }
  best_guess /= k;
  
  cout << "Best guess for 152.4 cm is " << best_guess << " kg" << endl;

  cout << endl;
  return 0;
}
