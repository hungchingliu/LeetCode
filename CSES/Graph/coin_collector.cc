#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  static void Solve(int n, const std::vector<int> &coins, const std::vector<std::vector<int>> &adjacent_list) {
    // strongly connected components, kosaraju's algorithm
    
    // 1. DFS to find dfs_order
    std::vector<bool> visited(n + 1, false);
    std::vector<int> dfs_order;

    for (int node = 1; node <= n; ++node) {
      if (!visited[node]) {
        visited[node] = true;
        DFS1(node, adjacent_list, visited, dfs_order);
      }
    }

    // 2. reverse dfs_order, reverse graph
    std::reverse(dfs_order.begin(), dfs_order.end());
    std::vector<std::vector<int>> adjacent_list_reverse(n + 1);

    for (int from = 1; from <= n; ++from) {
      for (int to: adjacent_list[from]) {
        adjacent_list_reverse[to].push_back(from);
      }
    }

    // 3. dfs to find SCCS
    std::vector<int> who(n + 1, 0);
    int count = 0;

    for (int node: dfs_order) {
      if (visited[node]) {
        visited[node] = false;
        ++count;
        who[node] = count; 
        DFS2(node, count, adjacent_list_reverse, visited, who);
      }
    }

    // 4. constuct SCC graph
    
    std::vector<std::vector<int>> scc_adjacent_list(count + 1);
    std::vector<long long> scc_sum(count + 1, 0);

    for (int node = 1; node <= n; ++node) {
      scc_sum[who[node]] += coins[node];
      for (int to: adjacent_list[node]) {
        if (who[node] != who[to]) {
          scc_adjacent_list[who[node]].push_back(who[to]);
        }
      }
    }

/*
    for (int i = 1; i <= n; ++i) {
      std::cout << who[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "SCC: " << count << std::endl;
    for (int i = 1; i <= count; ++i) {
      std::cout << scc_sum[i];
    }
    std::cout << std::endl;
*/

    // 5. DFS to find max sum;
    std::vector<bool> scc_visited(count + 1, false);
    std::vector<long long> dp(count + 1, 0);


    long long max_coins = 0;
    for (int node = 1; node <= count; ++node) {
      if (!scc_visited[node]) {
        scc_visited[node] = true;
        DFS3(node, scc_adjacent_list, scc_visited, scc_sum, dp);
      }
      max_coins = std::max(max_coins, dp[node]);
    }

    std::cout << max_coins;
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
    return;
  }

  static void DFS3(int node, const std::vector<std::vector<int>> &scc_adjacent_list,
                  std::vector<bool> &scc_visited, std::vector<long long> &scc_sum, std::vector<long long> &dp) {
    long long sum = 0;
    for (int to: scc_adjacent_list[node]) {
      if (!scc_visited[to]) {
        scc_visited[to] = true;
        DFS3(to, scc_adjacent_list, scc_visited, scc_sum, dp);
      }
      sum = std::max(sum, dp[to]);
    }
    dp[node] = scc_sum[node] + sum;
  }

};

int main() {
  // fast io
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> coins(n + 1, 0);
  std::vector<std::vector<int>> adjacent_list(n + 1);

  int coin;
  for (int i = 1; i <= n; ++i) {
    std::cin >> coin;
    coins[i] = coin;
  }

  int a, b;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    adjacent_list[a].push_back(b);
  }

  Solution::Solve(n, coins, adjacent_list);
  return 0;
}
