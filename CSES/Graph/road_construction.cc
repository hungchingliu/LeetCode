#include<iostream>
#include<vector>
#include<algorithm>

class DisjointSet {
 public:
  DisjointSet(int n) {
    parent_.resize(n + 1);
    size_.resize(n + 1, 1);
    set_count_ = n;
    max_size_ = 1;
    for (int i = 1; i <= n; ++i) {
      parent_[i] = i;
    }
  }

  int Find(int n) {
    if (parent_[n] != n) {
      parent_[n] = Find(parent_[n]);
    }

    return parent_[n];
  }

  void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) {
      return;
    }

    if (size_[a] > size_[b]) {
      parent_[b] = a;
      size_[a] += size_[b];
      max_size_ = std::max(size_[a], max_size_);
    }
    else {
      parent_[a] = b;
      size_[b] += size_[a];
      max_size_ = std::max(size_[b], max_size_);
    }
    
    --set_count_;
    return;
  }

  int Size() {
    return set_count_;
  }

  int MaxSize() {
    return max_size_;
  }


 private:
  std::vector<int> parent_;
  std::vector<int> size_;
  int set_count_;
  int max_size_;
};


class Solution {
 public:
  struct Edge{
    int from;
    int to;
  };
  
  static void Solve(int n, int m){

    DisjointSet disjoint_set(n);

    int from, to; 
    for (int i = 0; i < m; ++i) {
      std::cin >> from >> to;
      if (disjoint_set.Find(from) != disjoint_set.Find(to)) {
        disjoint_set.Union(from, to);
      }
      std::cout << disjoint_set.Size() << " " << disjoint_set.MaxSize() << '\n';
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m; 
  std::cin >> n >> m;
  Solution::Solve(n, m);

  return 0;
};
