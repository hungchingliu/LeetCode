#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  static void Solve(int n, std::vector<std::vector<int>> const &adjacent_list);
 private:
  static void DFS(
    int n, std::vector<int> &topological_sort, std::vector<bool> &visited,
    std::vector<bool> &processed,
    std::vector<std::vector<int>> const &adjacent_list,
    bool &contains_cycle);
};


void Solution::Solve(int n, std::vector<std::vector<int>> const &adjacent_list) {
  std::vector<int> topological_sort;
  std::vector<bool> processed(n + 1, false);
  std::vector<bool> visited(n + 1, false);
  bool contains_cycle = false;

  for (int i = 1; i <= n; i++) {
    if (!processed[i]) {
      DFS(i, topological_sort, visited, processed, adjacent_list, contains_cycle);
      if (contains_cycle) {
        break;
      }
    }
  }
  
  if (contains_cycle) {
    std::cout << "IMPOSSIBLE";
  } else {
    std::reverse(topological_sort.begin(), topological_sort.end());

    for (const int& node: topological_sort) {
      std::cout << node << " ";
    }
  }
  return;
}

void Solution::DFS(
    int n, std::vector<int> &topological_sort, std::vector<bool> &visited,
    std::vector<bool> &processed,
    std::vector<std::vector<int>> const &adjacent_list,
    bool &contains_cycle) {

  visited[n] = true;

  for (const int& next: adjacent_list[n]) {
    if (processed[next]) {
      continue;
    }

    if (visited[next]) {
      contains_cycle = true;
      return;
    }
    DFS(next, topological_sort, visited, processed, adjacent_list, contains_cycle);
  }

  topological_sort.push_back(n);
  processed[n] = true;
  return;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adjacent_list(n + 1);

  int a, b;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    adjacent_list[a].push_back(b);
  }

  Solution::Solve(n, adjacent_list);
}
