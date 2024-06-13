#include <iostream>
#include <vector>
#include <utility>


class UnionFind {
  std::vector<int> parent;
  std::vector<int> rank;

public:
  UnionFind(size_t size) {
    parent.resize(size + 1);
    rank.resize(size + 1, 0);

    for (size_t i = 1; i <= size; i++) {
      parent[i] = i;
    }
  }

  int Find(int x) {
    if (x != parent[x]) {
      parent[x] = Find(parent[x]);
    }
    return parent[x];
  }

  void Union(int x, int y) {
    int x_represent = Find(x);
    int y_represent = Find(y);

    if (x_represent == y_represent) {
      return;
    }

    if (rank[x_represent] > rank[y_represent]) {
      parent[y_represent] = x_represent;
    }
    else {
      parent[x_represent] = y_represent;
      if (rank[x_represent] == rank[y_represent]) {
        rank[y_represent]++;
      }
    }
    return;
  }
};

class Solution {

public:
  void Solve(int n, std::vector<std::pair<int, int> > &roads) {
    int count = 0;
    std::vector<std::pair<int, int> > new_roads;
    UnionFind disjoint_set(n);

    for (std::vector<std::pair<int, int> >::iterator it = roads.begin(); it != roads.end(); it++) {
      disjoint_set.Union(it->first, it->second);
    }


    for (int i = 2; i <= n; i++) {
      if (disjoint_set.Find(i - 1) != disjoint_set.Find(i)) {
        new_roads.push_back(std::make_pair(i - 1, i));
        disjoint_set.Union(i - 1, i);
        count++;
      }
    }

    std::cout << count << std::endl;
    for (std::vector<std::pair<int, int> >::iterator it = new_roads.begin(); it != new_roads.end(); it++) {
      std::cout << it->first << " " << it->second << std::endl;
    }

    return;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int> > roads;
  int a, b;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    roads.push_back(std::make_pair(a, b));
  }

  Solution().Solve(n, roads);
  return 0;
}
