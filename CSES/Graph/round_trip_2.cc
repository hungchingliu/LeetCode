#include <iostream>
#include <vector>
#include <algorithm>
 
class Solution {
 public:
  std::vector<int> cycle_path;
  bool found = false;
 
  void Solve(int n, std::vector<std::vector<int>> &adjacent_list) {
    std::vector<bool> visited(n + 1, false);
    std::vector<bool> is_parent(n + 1, false);
 
    std::vector<int> path;
 
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        DFS(i, adjacent_list, visited, is_parent, path);
      }
    }
 
    if (cycle_path.size() > 2) {
      std::cout << cycle_path.size() << std::endl;
      for (int node: cycle_path) {
        std::cout << node << " ";
      }
    } else {
      std::cout << "IMPOSSIBLE";
 
    }
}
 
  void DFS(int node, std::vector<std::vector<int>> &adjacent_list, std::vector<bool> &visited, 
          std::vector<bool> &is_parent, std::vector<int> &path) {
    if (found) {
      return;
    }
 
    if (is_parent[node]) {
      found = true;
      auto it = std::find(path.begin(), path.end(), node);
      cycle_path.insert(cycle_path.end(), it, path.end());
      cycle_path.push_back(node);
      return;
    }
 
    if (visited[node]) {
      return;
    }
    visited[node] = true;
 
 
    is_parent[node] = true;
    path.push_back(node);
 
    for (int to: adjacent_list[node]) {
      DFS(to, adjacent_list, visited, is_parent, path);
    }
    is_parent[node] = false;
    path.pop_back();
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
 
  Solution().Solve(n, adjacent_list);
}
