#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
 public:
  static void Solve(std::string s1, std::string s2) {
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int>> dp(n + 1);

    for (int i = 0; i <= n; ++i) {
      dp[i].resize(m + 1, 0);
      dp[i][0] = i;
    }

    for (int j = 0; j <= m; ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else {
          dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
        }
      }
    }

    std::cout << dp[n][m];
    return;
  }

};

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  Solution::Solve(s1, s2);
  return 0;
};
