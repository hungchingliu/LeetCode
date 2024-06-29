#include <iostream>
#include <vector>

class Solution {
 public:
  struct Edge {
    int u;
    int v;
  };

  static void Solve(int n, int m, const std::vector<int> &deg, std::vector<std::vector<int>> &adjacent_list, const std::vector<Edge> &edges) {

    if (!ContainEulerCircuit(n, deg)) {
      std::cout << "IMPOSSIBLE";
      return;
    }

    std::vector<int> euler_circuit;
    std::vector<bool> used(m + 1, false);
    euler_circuit.push_back(1);
    DFS(1, adjacent_list, edges, used, euler_circuit);

    
    if (euler_circuit.size() == m + 1) {
      for (int node: euler_circuit) {
        std::cout << node << " ";
      }
    } else {
      std::cout << "IMPOSSIBLE";
      return;
    }
    return;
  }

 private:
  static bool ContainEulerCircuit(int n, const std::vector<int> &deg) {
    bool success = true;
    for (int node = 1; node <= n; ++node) {
      if (deg[node] % 2 == 1) {
        success = false;
      }
    }
    return success;
  }

  static void DFS(int node, std::vector<std::vector<int>> &adjacent_list,
                  const std::vector<Edge> &edges, std::vector<bool> &used, std::vector<int> &euler_circuit) {
    while (adjacent_list[node].size()) {
      int edge_index = adjacent_list[node].back();
      adjacent_list[node].pop_back();
      if (used[edge_index]) {
        continue;
      }
      used[edge_index] = true;
      auto [u, v] = edges[edge_index];
      if (u == node) {
        DFS(v, adjacent_list, edges, used, euler_circuit);
      } else {
        DFS(u, adjacent_list, edges, used, euler_circuit);
      }
      euler_circuit.push_back(node);
    }
    return;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> deg(n + 1, 0);
  std::vector<Solution::Edge> edges(m + 1);
  std::vector<std::vector<int>> adjacent_list(n + 1);

  int a, b;
  for (int i = 1; i <= m; ++i) {
    std::cin >> a >> b;
    ++deg[a];
    ++deg[b];

    edges[i] = Solution::Edge({a, b});
    adjacent_list[a].push_back(i);
    adjacent_list[b].push_back(i);
  }

  Solution::Solve(n, m, deg, adjacent_list, edges);
  return 0;
};
