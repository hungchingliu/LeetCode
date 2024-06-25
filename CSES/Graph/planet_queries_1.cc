#include <iostream>
#include <array>
#include <vector>
#include <utility>

class Solution {
 public: 
  static void Solve(std::vector<int> &teleport, std::vector<std::pair<int, int>> &queries) {
    int n = teleport.size();

    std::array<std::vector<int>, 31> successor;

    for (int i = 0; i < 31; ++i) {
      successor[i].resize(n + 1);
    }

    for (int i = 0; i < 31; ++i) {
      for (int j = 1; j <= n; j++) {
        if (i == 0) {
          successor[0][j] = teleport[j];
        }
        else {
          successor[i][j] = successor[i - 1][successor[i - 1][j]];
        }
      }
    }

    for (auto[x, k]: queries) {
      for (int j = 0; j <= 30; j++) {
        if (k & (1 << j)) {
          x = successor[j][x];
        }
      }
      std::cout << x << '\n';
    }
    return;
  }
};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, q;

  std::cin >> n >> q;

  std::vector<int> successor(n + 1);

  int t;
  for (int i = 1; i <= n; i++) {
    std::cin >> t;
    successor[i] = t;
  }

  std::vector<std::pair<int, int>> queries(q);

  int x, k;
  for (int i = 0; i < q; ++i) {
    std::cin >> x >> k;
    queries[i] = std::make_pair(x, k);

  }

  Solution::Solve(successor, queries);

  return 0;
} 

