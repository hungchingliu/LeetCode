#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
 public:
  static void Solve(int n, const std::vector<std::vector<int>> &adjacent_list) {

    // Kosaraju's algorithm

    // 1. Find DFS order
    std::vector<int> dfs_order;
    std::vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        visited[i] = true;
        DFS(i, adjacent_list, visited, dfs_order);
      }
    }

    // 2. Reverse DFS dfs_order and reverse adjacent_list
    std::reverse(dfs_order.begin(), dfs_order.end());

    std::vector<std::vector<int>> adjacent_list_reverse;
    adjacent_list_reverse.resize(n + 1);

    for (int from = 1; from <= n; ++from) {
      for (int to: adjacent_list[from]) {
        adjacent_list_reverse[to].push_back(from);
      }
    }

    // 3. DFS to find stronly connected component
    std::vector<int> component(n + 1, 0);
    int strongly_connected_components_count = 0;


    for (int node: dfs_order) {
      if (visited[node]) {
        visited[node] = false;
        int root = node;
        component[node] = root;
        DFS2(node, root, adjacent_list_reverse, visited, component);
      }
    }


    std::map<int, int> root_to_index;

    for (int i = 1; i <= n; ++i) {
      // root
      if (i == component[i]) {
        ++strongly_connected_components_count;
        root_to_index[i] = strongly_connected_components_count;
      }
    }

    for (int i = 1; i <= n; i++) {
      root_to_index[i] = root_to_index[component[i]];
    }

    std::cout << strongly_connected_components_count << '\n';
    for (int i = 1; i <= n; ++i) {
      std::cout << root_to_index[i] << " ";
    }
    return;

  }

 private:
  static void DFS(int node, const std::vector<std::vector<int>> &adjacent_list,
           std::vector<bool> &visited, std::vector<int> &dfs_order) {

    for (int to: adjacent_list[node]) {
      if (!visited[to]) {
        visited[to] = true;
        DFS(to, adjacent_list, visited, dfs_order);
      }
    }

    dfs_order.push_back(node);
    return;
  }

  static void DFS2(int node, int root, const std::vector<std::vector<int>> &adjacent_list_reverse,
            std::vector<bool> &visited, std::vector<int> &component) {

    for (int to: adjacent_list_reverse[node]) {
      if (visited[to]) {
        visited[to] = false;
        component[to] = root;
        DFS2(to, root, adjacent_list_reverse, visited, component);
      }
    }
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
};
