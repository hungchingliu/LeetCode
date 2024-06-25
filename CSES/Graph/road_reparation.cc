#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet {
 public: 
  DisjointSet(int n) {
    parent_.resize(n + 1);
    rank_.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      parent_[i] = i;
      rank_[i] = 0;
    }
  }

  int find(int n) {
    if (parent_[n] != n) {
      parent_[n] = find(parent_[n]);
    }
    return parent_[n];
  }

  void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) {
      return;
    }

    if (rank_[a] > rank_[b]) {
      parent_[b] = a;
    }
    else {
      parent_[a] = b;
      if (rank_[a] == rank_[b]) {
        ++rank_[b];
      }
    }

    return;
  }
 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

class Solution {
 public:
  struct Edge {
    int from;
    int to;
    int weight;
  };

  static void Solve(int n, std::vector<Edge> edges){
    DisjointSet disjoint_set(n + 1);

    
    std::sort(edges.begin(), edges.end(), EdgeCompare);

    long long int count = 0;
    for (auto [from, to, weight]: edges) {
      if (disjoint_set.find(from) != disjoint_set.find(to)) {
        disjoint_set.Union(from, to);
        count += weight;
      }
    }

    bool success = true;
    for (int i = 2; i <= n; ++i) {
      if (disjoint_set.find(1) != disjoint_set.find(i)) {
        success = false;
      }
    }

    if (success) {
      std::cout << count;
    } else {
      std::cout << "IMPOSSIBLE";
    }

    return;
  }

 private: 
  static bool EdgeCompare(const Edge &lhs, const Edge &rhs) {
    return lhs.weight < rhs.weight;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<Solution::Edge> edges;
  
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  Solution::Solve(n, edges);
  return 0;
};
