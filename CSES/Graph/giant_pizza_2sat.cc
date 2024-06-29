#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  static void Solve(int n, const std::vector<std::vector<int>> &adjacent_list) {
    // kosaraju's algorithm

    // 1. DFS to build dfs_order
    std::vector<int> dfs_order;
    std::vector<bool> visited(n + 1, false);

    for (int node = 1; node <= n; ++node) {
      if (!visited[node]) {
        visited[node] = true;
        DFS1(node, adjacent_list, visited, dfs_order);
      }
    }

    // 2. reverse dfs order, and construct reverse graph

    std::reverse(dfs_order.begin(), dfs_order.end());
    std::vector<std::vector<int>> adjacent_list_reverse;
    adjacent_list_reverse.resize(n + 1);

    for (int from = 1; from <= n; ++from) {
      for (int to: adjacent_list[from]) {
        adjacent_list_reverse[to].push_back(from);
      }
    }

    // 3. DFS by dfs order to construct strongly connected components

    std::vector<int> who(n + 1, 0);
    int components_count = 0;

    for (int node: dfs_order) {
      if (visited[node]) {
        visited[node] = false;
        ++components_count;
        who[node] = components_count;
        DFS2(node, components_count, adjacent_list_reverse, visited, who);
      }
    }

    // 4. find a valid solution for 2sat
    bool success = true;
    std::vector<char> two_sat(n / 2 + 1, 0);

    for (int node = 1; node <= n / 2; ++node) {
      if (who[node] == who[n/2 + node]) {
        success = false;
        break;
      }

      two_sat[node] = (who[node] < who[n/2 +  node]) ? '-' : '+';
    }

    if (success) {
      for (int i = 1; i <= n / 2; ++i) {
        std::cout << two_sat[i] << " ";
      }
    } else {
      std::cout << "IMPOSSIBLE";
    }

    return;
  }
 private:
  static void DFS1(int node, const std::vector<std::vector<int>> &adjacent_list,
                  std::vector<bool> &visited, std::vector<int> &dfs_order) {
    for (int to: adjacent_list[node]) {
      if (!visited[to]) {
        visited[to] = true;
        DFS1(to, adjacent_list, visited, dfs_order);
      }
    }

    dfs_order.push_back(node);
    return;
  }

  static void DFS2(int node, int index, const std::vector<std::vector<int>> &adjacent_list_reverse,
                   std::vector<bool> &visited, std::vector<int> &who) {
    for (int to: adjacent_list_reverse[node]) {
      if (visited[to]) {
        visited[to] = false;
        who[to] = index;
        DFS2(to, index, adjacent_list_reverse, visited, who);
      }
    }
  }
};

int main() {
  int n, m;

  std::cin >> n >> m;

  std::vector<std::vector<int>> adjacent_list;
  adjacent_list.resize(2 * m + 1);

  char sign_a, sign_b;
  int a, b;
  int from, to;
  for (int i = 0; i < n; ++i) {
    std::cin >> sign_a >> a >> sign_b >> b;
    
    if (sign_a == '-') {
      a = -a;
    }

    if (sign_b == '-') {
      b = -b;
    }

    // add -a -> b 
    if (-a < 0) {
      from = m + a;
    } else {
      from = -a;
    }

    if (b < 0) {
      to = m - b;
    } else {
      to = b;
    }
    adjacent_list[from].push_back(to);
    
    // add -b -> a
    if (-b < 0) {
      from = m + b;
    } else {
      from = -b;
    }

    if (a < 0) {
      to = m - a;
    } else {
      to = a;
    }
    adjacent_list[from].push_back(to);
  }

  Solution::Solve(2 * m, adjacent_list);
  return 0;
};
