#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
 public:
  void Solve(int n, const std::vector<std::vector<int>> &adjacent_list) {
    const int kNINF = -1e8;
    std::vector<int> topological_sort = TopologicalSort(n, adjacent_list);

    std::vector<int> city_count(n + 1, kNINF);
    std::vector<int> parent(n + 1, 0);

    city_count[1] = 1;

    for (int node: topological_sort) {
      for (int next: adjacent_list[node]) {
        if (city_count[node] == kNINF) {
          continue;
        }
        if (city_count[node] + 1 > city_count[next]) {
          city_count[next] = city_count[node] + 1;
          parent[next] = node;
        }
      }
    }

    if (city_count[n] == kNINF) {
      std::cout << "IMPOSSIBLE";
      return;
    }

    std::vector<int> path;
    int index = n;

    while(index != 1 && index != 0) {
      path.push_back(index);
      index = parent[index];
    }
    path.push_back(1);

    std::reverse(path.begin(), path.end());

    std::cout << city_count[n] << std::endl;
    for (int city: path) {
      std::cout << city << " ";
    }
    return;
  }

  std::vector<int> TopologicalSort(int n, const std::vector<std::vector<int>> &adjacent_list) {

    std::vector<bool> visited(n + 1, false);
    std::vector<bool> processed(n + 1, false);
    std::vector<int> topological_sort;

    for (int i = 1; i <= n; i++) {
      if (!processed[i]) {
        DFS(i, adjacent_list, visited, processed, topological_sort);
      }
    }

    std::reverse(topological_sort.begin(), topological_sort.end());

    return topological_sort;
  }

  void DFS(int node, const std::vector<std::vector<int>> &adjacent_list,
          std::vector<bool> &visited,
          std::vector<bool> &processed,
          std::vector<int> &topological_sort) {

    visited[node] = true;
  
    for (int next: adjacent_list[node]) {
      if (!visited[next] && !processed[next]) {
        DFS(next, adjacent_list, visited, processed, topological_sort);
      }
    }

    topological_sort.push_back(node);
    processed[node] = true;
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

  Solution().Solve(n, adjacent_list);
  return 0;
}
