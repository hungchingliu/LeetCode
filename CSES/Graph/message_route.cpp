#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <algorithm>


class Solution {
  
  struct Node {
      int index;
      int distance;
  };

public:
  void Solve(int n, std::vector<std::vector<int> > &adjacent_list) {
    
    std::vector<bool> visited;
    std::vector<int> parent;


    std::queue<Node> queue;
    bool success = false;
    int min_distance = std::numeric_limits<int>::max();

    visited.resize(n + 1, false);
    parent.resize(n + 1, 0);

    queue.push({1, 0});
    visited[1] = true;

    while (!queue.empty()) {
      
      Node node = queue.front();
      queue.pop();

      if (node.index == n) {
        success = true;
        min_distance = node.distance;
        break;
      }

      for (int i = 0; i < adjacent_list[node.index].size(); i++) {
        int next_node_index = adjacent_list[node.index][i];
        if (!visited[next_node_index]) {
          visited[next_node_index] = true;
          parent[next_node_index] = node.index;
          queue.push({next_node_index, node.distance + 1});
        }
      }
    }
    if (!success) {
      std::cout << "IMPOSSIBLE" << std::endl;
    } else {
      std::vector<int> backtrack_path;
      int index = n;
      while (index != 1) {
        backtrack_path.push_back(index);
        index = parent[index];
      }

      backtrack_path.push_back(1);
      std::reverse(backtrack_path.begin(), backtrack_path.end());

      std::cout << min_distance + 1 << std::endl;
      for (std::vector<int>::iterator it = backtrack_path.begin(); it != backtrack_path.end(); it++) {
        std::cout << *it << " ";
      }
    }

    return;
  }

};

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > adjacent_list;
  adjacent_list.resize(n + 1);


  int a, b;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    adjacent_list[a].push_back(b);
    adjacent_list[b].push_back(a);
  }
  
  Solution().Solve(n, adjacent_list);
  return 0;
}
