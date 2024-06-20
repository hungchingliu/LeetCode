#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


struct AdjacentListItem {
  int to;
  int weight;
};

struct PriorityQueueItem {
  int node;
  long long distance;
};

struct ComparePriorityQueueItem {
  bool operator() (const PriorityQueueItem &below, const PriorityQueueItem &above) {
    if (below.distance > above.distance) {
      return true;
    }
    return false;
  }
};

void Solve(int n, int k, std::vector<std::vector<AdjacentListItem>> adjacent_list) {

  std::vector<std::vector<long long int>> distance;
  distance.resize(n + 1);

  std::priority_queue<
    PriorityQueueItem,
    std::vector<PriorityQueueItem>,
    ComparePriorityQueueItem> priority_queue;

  priority_queue.push({1, 0});

  // modified dijkstra 
  while (!priority_queue.empty()) {
    auto [node, node_distance] = priority_queue.top();
    priority_queue.pop();

    if (distance[node].size() == k) {
      continue;
    }
    distance[node].push_back(node_distance);

    for (auto [to, weight]: adjacent_list[node]) {

      long long int to_dist = node_distance + weight;
      priority_queue.push({to, to_dist});
    }
  }       

  for (long long dist: distance[n]) {
    std::cout << dist << " ";
  }

  return;
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<AdjacentListItem>> adjacent_list;

  adjacent_list.resize(n + 1);

  int a, b, c;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b >> c;
    adjacent_list[a].push_back({b, c});
  }

  Solve(n, k, adjacent_list);
  return 0;

}


