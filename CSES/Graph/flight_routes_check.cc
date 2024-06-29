#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  static void Solve(int n, std::vector<std::vector<int>> adjacent_list) {
    // implement Kosaraju's algorithm
    
    // 1. DFS to find process order
    std::vector<bool> visited(n + 1, false);
    std::vector<int> dfs_order;

    for(int i = 1; i <= n; ++i) {
      DFS1(i, adjacent_list, visited, dfs_order);
    }
    std::reverse(dfs_order.begin(), dfs_order.end());


    // 2. construct reverse graph
    std::vector<std::vector<int>> adjacent_list_reverse(n + 1);
    for (int i = 1; i <= n; ++i) {
      for (int to: adjacent_list[i]) {
        adjacent_list_reverse[to].push_back(i);
      }
    }

    // 3. DFS by dfs_order to find strongly connected component
    std::vector<int> component(n + 1, 0);
    visited.assign(visited.size(), false);
    std::vector<int> roots;
    int a = 0;
    int b = 0;
    for (int node: dfs_order) {
      if (!visited[node]) {
        int root = node;
        roots.push_back(root);
        visited[node] = true;
        DFS2(node, root, adjacent_list_reverse, visited, component);
        if (a == 0) {
          a = node;
        }
        else if (b == 0) {
          b = node;
          break;
        }
      }

    }

    if (b == 0) {
      std::cout << "YES";
    }
    else {
      std::cout << "NO" << '\n';
      std::cout << b << " " << a;
    }
    return;
  }
 private:
  static void DFS1(int node, std::vector<std::vector<int>> &adjacent_list,
           std::vector<bool> &visited, std::vector<int> &dfs_order) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;

    for(int to: adjacent_list[node]) {
      DFS1(to, adjacent_list, visited, dfs_order);
    }

    dfs_order.push_back(node);
    return;
  } 

  static void DFS2(int node, int root, std::vector<std::vector<int>> &adjacent_list_reverse,
            std::vector<bool> &visited,  std::vector<int> &component) {

    // std:: cout << "node: " << node << " root: " << root << std::endl;

    for (int to: adjacent_list_reverse[node]) {
      // std::cout << to << std::endl;
      if (!visited[to]) {
        visited[to] = true;
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

  std::vector<std::vector<int>> adjacent_list(n + 1);

  int a, b;

  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    adjacent_list[a].push_back(b);
  }

  Solution::Solve(n, adjacent_list);
  return 0;
} 



