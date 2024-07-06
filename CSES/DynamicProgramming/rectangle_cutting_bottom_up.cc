#include <iostream>
#include <vector>

class Solution {
 public:
  static void Solve(int a, int b) {
    if (a > b) {
      std::swap(a, b);
    }

    std::vector<std::vector<int>> dp(b + 1);
    for (int i = 0; i <= b; ++i) {
      dp[i].resize(b + 1, -1);
    }

    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        if (i == j) {
          dp[i][j] = 0;
          continue;
        }
        int min = -1;
        for (int slice = 1; slice < i; ++slice) {
          if (min == -1) {
            min = dp[slice][j] + dp[i - slice][j] + 1;
          }
          else {
            min = std::min(min, dp[slice][j] + dp[i - slice][j] + 1);
          }
        }

        for (int slice = 1; slice < j; ++slice) {
          if (min == -1) {
            min = dp[i][slice] + dp[i][j - slice] + 1;
          }
          else {
            min = std::min(min, dp[i][slice] + dp[i][j - slice] + 1);
          }
        }

        dp[i][j] = min;
      }
    }
    std::cout << dp[a][b];
  }
};

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a, b;
  std::cin >> a >> b;
  Solution::Solve(a, b);
  return 0;
}
