#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
 public:
  static void Solve(int n, const std::vector<std::vector<int>> &adjacent_list) {

    const int kMod = 1e9 + 7;

    std::vector<int> topological_sorted_vector = TopologicalSort(n, adjacent_list);

    std::vector<int> path_count(n + 1, 0);

    path_count[1] = 1;

    for (int current_node: topological_sorted_vector) {
      for (int next_node: adjacent_list[current_node]) {
        path_count[next_node] += path_count[current_node];
        path_count[next_node] %= kMod;
      }
    }

    std::cout << path_count[n];
    return;
  }

  static std::vector<int> TopologicalSort(int n, const std::vector<std::vector<int>> &adjacent_list) {
    std::vector<bool> visited(n + 1, false);
    std::vector<bool> processed(n + 1, false);
    std::vector<int> sorted_vector;

    for (int i = 1; i <= n; ++i) {
      if (!processed[i]) {
        DFS(i, adjacent_list, visited, processed, sorted_vector);
      }
    }

    std::reverse(sorted_vector.begin(), sorted_vector.end());

    return sorted_vector;
  }

  static void DFS(
    int node,
    const std::vector<std::vector<int>> &adjacent_list,
    std::vector<bool> &visited,
    std::vector<bool> &processed,
    std::vector<int> &sorted_vector) {

    visited[node] = true;

    for (int next: adjacent_list[node]) {
      if (!visited[next] && !processed[next]) {
        DFS(next, adjacent_list, visited, processed, sorted_vector);
      }
    }

    processed[node] = true;
    sorted_vector.push_back(node);
    return;
  }
};


int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adjacent_list;
  adjacent_list.resize(n + 1);

  int a, b;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    adjacent_list[a].push_back(b);
  }

  Solution::Solve(n, adjacent_list);
  return 0;
}
