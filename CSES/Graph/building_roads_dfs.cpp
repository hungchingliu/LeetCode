#include <iostream>
#include <vector>


class Solution {
  std::vector<bool> visited;
  
public:
  void Solve(int n, std::vector<std::vector<int> > &adjacent_list){

    visited.resize(n + 1, false);

    std::vector<int> connected_components;

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        connected_components.push_back(i);
        DFS(i, adjacent_list);
      }
    }

    std::cout << connected_components.size() - 1 << std::endl;

    for (int i = 1; i < connected_components.size(); i++) {
      std::cout << connected_components[i - 1] << " " << connected_components[i] << std::endl;
    }

    return;
  }

private:

  void DFS(int node, std::vector<std::vector<int> > &adjacent_list) {
    visited[node] = true;

    for (int i = 0; i < adjacent_list[node].size(); i++) {
      if (!visited[adjacent_list[node][i]]) {
        DFS(adjacent_list[node][i], adjacent_list);
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
