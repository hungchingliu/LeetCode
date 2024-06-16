#include <iostream>
#include <vector>

class Solution {
  std::vector<bool> visited_;
  std::vector<std::vector<int>> adjacent_list_;
  std::vector<int> parent_;
  std::vector<int> path_;
  bool success_ = false;

 public:
  void Solve(int n, std::vector<std::vector<int>> &adjacent_list) {
    visited_.resize(n + 1, false);
    parent_.resize(n + 1, 0);
    adjacent_list_ = adjacent_list;

    for (int i = 1; i <= n; i++) {
      if (!visited_[i]) {
        visited_[i] = true;
        DFS(i, 0);
        if (success_) {
          break;
        }
      }
    }

    if (success_) {
      std::cout << path_.size() << std::endl;
      for (auto &node: path_) {
        std::cout << node << " ";
      }
    }
    else {
      std::cout << "IMPOSSIBLE";
    }
    return;
  }

 private:
  void DFS(int node, int previous_node) {
    
    for (auto &next: adjacent_list_[node]){
      if (!visited_[next]) {
        visited_[next] = true;
        parent_[next] = node;
        DFS(next, node);
      }
      else {
        if (next == previous_node) {
          continue;
        }

        success_ = true;
        path_.push_back(next);
        int it = node;
        while (it != next) {
          path_.push_back(it);
          it = parent_[it];
        }
        path_.push_back(next);
      }

      if (success_) {
        return;
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
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    adjacent_list[a].push_back(b);
    adjacent_list[b].push_back(a);
  }

  Solution().Solve(n, adjacent_list);
  return 0;
}
