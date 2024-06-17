#include <iostream>
#include <queue>
#include <vector>
#include <limits>

class Solution {
 public:

  struct Node {
    long long int distance;
    int index;
  };

  struct CompareNode {
    bool operator() (Node const &below, Node const &above) {
      if (below.distance > above.distance) {
        return true;
      }
      return false;
    }
  };

  void Solve(int n, std::vector<std::vector<std::pair<int, int>>> adjacent_list) {
    std::priority_queue<Node, std::vector<Node>, CompareNode> priority_queue;

    std::vector<int> visited(n + 1, false);

    std::vector<long long int> distance(n + 1, -1);
    distance[1] = 0;

    priority_queue.push({0, 1});

    while (!priority_queue.empty()) {
      Node node = priority_queue.top();
      priority_queue.pop();

      if (visited[node.index]) {
        continue;
      }

      visited[node.index] = true;

      for (auto &next: adjacent_list[node.index]) {
        int to = next.first;
        int weight = next.second;
        if (distance[to] == -1 || distance[node.index] + weight < distance[to]) {
          distance[to] = distance[node.index] + weight;
          priority_queue.push({distance[to], to});
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      std::cout << distance[i] << " ";
    }

    return;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> adjacent_list;
  adjacent_list.resize(n + 1);

  int a, b, c;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    adjacent_list[a].push_back({b, c});
  }

  Solution().Solve(n, adjacent_list);

  return 0;
}
