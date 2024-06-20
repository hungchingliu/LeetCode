#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
 public:
  struct Edge {
    int from;
    int to;
    int weight;
  };

  static void Solve(int n, std::vector<Edge> &edges) {
    std::vector<int> parent(n + 1, 0);

    std::vector<long long int> distance(n + 1, 0);


    // bellman ford
    for (int i = 1 ; i <= n - 1; ++i) {
      for (auto edge: edges) {
        int from = edge.from;
        int to = edge.to;
        int weight = edge.weight;

        if (distance[from] + weight < distance[to]) {
          distance[to] = distance[from] + weight;
          parent[to] = from;
        }
      }
    }

    bool find_cycle = false;
    int cycle = -1;
    for (auto edge: edges) {
      int from = edge.from;
      int to = edge.to;
      int weight = edge.weight;
      if (distance[from] + weight < distance[to]) {
        distance[to] = distance[from] + weight;
        parent[to] = from;
        find_cycle = true;
        cycle = to;
        break;
      }
    }
    
    if (!find_cycle) {
      std::cout << "NO";
    } else {
      std::cout << "YES" << std::endl;

      for (int i = 1; i <= n - 1; i++) {
        cycle = parent[cycle];
      }

      std::vector<bool> cycle_visited(n + 1, false);

      std::vector<int> path;
      int index = parent[cycle];

      while (!cycle_visited[index]) {
        cycle_visited[index] = true;
        path.push_back(index);
        index = parent[index];
      }


      std::reverse(path.begin(), path.end());
      std::cout << cycle << " ";
      for (auto &node: path) {
        if (node != cycle){
          std::cout << node << " ";
        }
      }
      std::cout << cycle << " ";
    }

    return;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Solution::Edge> edges;

  int a, b, c;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  Solution::Solve(n, edges);
  return 0;
} 


