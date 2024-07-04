#include <iostream>
#include <vector>

class Solution {
 public:
  static void Solve(int n, const std::vector<std::vector<char>> &map) {
    std::vector<std::vector<int>> dp(n);

    for (int i = 0; i < n; ++i) {
      dp[i].resize(n);
    }

    if (map[0][0] == '*') {
      std::cout << 0;
      return;
    }
    else if(map[0][0] == '.') {
      dp[0][0] = 1;
    }


    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          continue;
        }

        if (map[i][j] == '*') {
          continue;
        }
        else if (map[i][j] == '.') {
          if (i - 1 >= 0) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= kMOD;
          }
          if (j - 1 >= 0) {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= kMOD;
          }
        }
      }
    }

    std::cout << dp[n - 1][n - 1];
    return;
  }
 private:
  static const int kMOD = 1e9 + 7;
};

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<char>> map(n);

  char c;
  for (int i = 0; i < n; ++i) {
    map[i].resize(n);
    for (int j = 0; j < n; ++j) {
      std::cin >> c;
      map[i][j] = c;
    }
  }

  Solution::Solve(n, map);
  return 0;
};


