#include <iostream>
#include <limits>
#include <vector>

class Solution {
 public:
  struct Edge {
    int start;
    int end;
    long long int weight;
  };
  
  void Solve(int n, std::vector<Edge> const &edges, std::vector<std::vector<int>> const &adjacent_list) {

    std::vector<long long int> scores(n + 1, 0);
    std::vector<bool> visited(n + 1, false);

    scores[1] = 0;
    visited[1] = true;

    for (int i = 1; i <= n - 1; i++) {
      for (auto &edge: edges) {
        int start = edge.start;
        int end = edge.end;
        long long int weight = edge.weight;

        if (!visited[start]) {
          continue;
        }
        else if (!visited[end]) {
          scores[end] = scores[start] + weight;
          visited[end] = true;
        }
        else {
          if (scores[start] + weight > scores[end]) {
            scores[end] = scores[start] + weight;  
          }
          
        }
      }
    }

    long long int max_score = scores[n];

    std::vector<int> cycle_nodes;

    for (auto &edge: edges) {
      int start = edge.start;
      int end = edge.end;
      int weight = edge.weight;
      if (!visited[start]) {
          continue;
        }
      else if (!visited[end]) {
          scores[end] = scores[start] + weight;
          visited[end] = true;
        }
      else if (scores[start] + weight > scores[end]){
        cycle_nodes.push_back(end);
      }
    }

    bool contains_positive_cycle = false;
    for (auto &node: cycle_nodes) {
      std::vector<bool> dfs_visited(n + 1, false);
      DFS(node, n, adjacent_list, dfs_visited, contains_positive_cycle);
      if (contains_positive_cycle) {
        break;
      }
    }

    if (contains_positive_cycle) {
      std::cout << -1;
    } else {
      std::cout << max_score;
    }

    return;
  }

  void DFS(int node, int n, std::vector<std::vector<int>> const &adjacent_list,
      std::vector<bool> &dfs_visited, bool &contains_positive_cycle) {
    if (node == n) {
      contains_positive_cycle = true;
      return;
    }

    for (int next: adjacent_list[node]) {
      if (!dfs_visited[next]) {
        dfs_visited[next] = true;
        DFS(next, n, adjacent_list, dfs_visited, contains_positive_cycle);
      }
    }
  }

};

int main() {
  int n, m;

  std::cin >> n >> m;

  std::vector<Solution::Edge> edges;
  std::vector<std::vector<int>> adjacent_list;
  adjacent_list.resize(n + 1);

  int a, b, x;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> x;
    edges.push_back({a, b, x});
    adjacent_list[a].push_back(b);
  }

  Solution().Solve(n, edges, adjacent_list);
  return 0;
}
