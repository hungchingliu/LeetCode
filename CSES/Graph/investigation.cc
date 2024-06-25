#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Solution {
 public:
  const long long kINF = 1e17;
  const long long kMOD = 1e9 + 7;

  struct AdjacentListItem {
    int to;
    int weight;
  };

  void Solve(int n, const std::vector<std::vector<AdjacentListItem>> &adjacent_list) {

    auto [min_price, dijkstra_graph_adjacent_list] = Dijkstra(n, adjacent_list);
    std::vector<int> sorted_nodes = TopologicalSort(n, dijkstra_graph_adjacent_list);

    std::vector<long long> total_path(n + 1, 0);
    std::vector<long long> max_nodes(n + 1, 0);
    std::vector<long long> min_nodes(n + 1, kINF);

    total_path[1] = 1;

    for (int node: sorted_nodes) {
      for (auto [to, weight]: dijkstra_graph_adjacent_list[node]) {
        total_path[to] += total_path[node];
        total_path[to] %= kMOD;
      }
    }

    std::vector<std::vector<int>> reverse_edges;
    reverse_edges.resize(n + 1);

    for (int i = 1; i <= n; i++) {
      for (auto [to, weight]: dijkstra_graph_adjacent_list[i]) {
        reverse_edges[to].push_back(i);
      }
    }


    min_nodes[1] = 0;
    max_nodes[1] = 0;

    for (int node:sorted_nodes) {
      if (node == 1) {
        continue;
      }

      for (int parent: reverse_edges[node]) {
        min_nodes[node] = std::min(min_nodes[node], min_nodes[parent] + 1);
        max_nodes[node] = std::max(max_nodes[node], max_nodes[parent] + 1);
      }
    }

    std::cout << min_price[n] << " " << total_path[n] << " " << min_nodes[n] << " " << max_nodes[n];
    return;
  }

 private:
  struct DijkstraByproduct {
    std::vector<long long> min_distance;
    std::vector<std::vector<AdjacentListItem>> adjacent_list;
  };

  struct PriorityQueueItem {
    int node;
    int parent;
    int weight;
    long long distance;
  };

  struct PriorityQueueItemCompare {
     bool operator() (const PriorityQueueItem &below, const PriorityQueueItem &above) {
      if (below.distance > above.distance) {
        return true;
      }
      return false;
    }
  };

  DijkstraByproduct Dijkstra(int n, const std::vector<std::vector<AdjacentListItem>> &adjacent_list) {

    std::vector<long long > min_distance(n + 1, kINF);
    std::vector<std::vector<AdjacentListItem>> dijkstra_graph_adjacent_list(n + 1);

    std::priority_queue<PriorityQueueItem, std::vector<PriorityQueueItem>, PriorityQueueItemCompare> priority_queue;

    min_distance[1] = 0;
    priority_queue.push(PriorityQueueItem{.node = 1, .parent = 0, .weight = 0, .distance = 0});

    while (!priority_queue.empty()) {
      auto [node, parent, weight, distance] = priority_queue.top();
      priority_queue.pop();

      if (distance > min_distance[node]) {
        continue;
      }

      for (auto const &[to, weight]: adjacent_list[node]) {
        if (min_distance[node] + weight < min_distance[to]) {
          min_distance[to] = min_distance[node] + weight;
          priority_queue.push(PriorityQueueItem{.node = to, .parent = node, .weight = weight, .distance = min_distance[to]});
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      for (auto[to, weight]: adjacent_list[i]) {
        if (min_distance[to] == min_distance[i] + weight) {
          dijkstra_graph_adjacent_list[i].push_back(AdjacentListItem{.to = to, .weight = weight});
        }
      }
    }


    return DijkstraByproduct{min_distance, dijkstra_graph_adjacent_list};
  }

  std::vector<int> TopologicalSort(int n, std::vector<std::vector<AdjacentListItem>> &adjacent_list) {
    std::vector<int> sorted_nodes;
    std::vector<bool> visited(n + 1, false);
    std::vector<bool> processed(n + 1, false);
 
    // Though dijkstra graph is connected, I write a general version of topological sort
    for (int i = 1; i <= n; ++i) {
      if (!processed[i]) {
        DFS(1, adjacent_list, visited, processed, sorted_nodes);
      }      
    }

    std::reverse(sorted_nodes.begin(), sorted_nodes.end());
    return sorted_nodes;
  }

  void DFS(
      int node,
      const std::vector<std::vector<AdjacentListItem>> &adjacent_list,
      std::vector<bool> &visited,
      std::vector<bool> &processed,
      std::vector<int> &sorted_nodes) {
    visited[node] = true;

    for (auto [to, weight]: adjacent_list[node]) {
      if (!visited[to] && !processed[to]) {
        DFS(to, adjacent_list, visited, processed, sorted_nodes);
      }
    }

    processed[node] = true;
    sorted_nodes.push_back(node);
    return;
  }
};


int main() {
  int m, n;
  std::cin >> n >> m;

  std::vector<std::vector<Solution::AdjacentListItem>> adjacent_list;
  adjacent_list.resize(n + 1);

  int a, b, c;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b >> c;
    adjacent_list[a].push_back(Solution::AdjacentListItem{.to = b, .weight = c});
  }
 
  Solution().Solve(n, adjacent_list);
  return 0;
}
