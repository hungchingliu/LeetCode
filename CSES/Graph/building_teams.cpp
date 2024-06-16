#include <iostream>
#include <vector>
#include <queue>

class Solution {
 public:
  void Solve(int n, std::vector<std::vector<int>> adjacent_list) {
    std::vector<bool> visited(n + 1, false);
    std::vector<int> distance(n + 1, 0);
    std::vector<int> group(n + 1, 0);
    
    std::queue<int> queue;


    bool success = true;

    for (int i = 1; i <= n; i++) {

      if (!visited[i]) {
        queue.push(i);
        visited[i] = true;
        group[i] = 1;
      }

      while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int j = 0; j < adjacent_list[node].size(); j++) {
          int next = adjacent_list[node][j];
          if (!visited[next]) {
            visited[next] = true;

            group[next] = (group[node] == 1) ? 2 : 1;
            queue.push(next);
          } else if (group[node] == group[next]) {
              success = false;
              break;
          }
        }

        if (!success) {
          break;
        }
      }

      if (!success) {
        break;
      }
    }

    if (success) {
      for (int i = 1; i <= n; i++) {
        std::cout << group[i] << " ";
      }
    }
    else {
      std::cout << "IMPOSSIBLE";
    }
    return;
  }
};


int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int >> adjacent_list;
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
