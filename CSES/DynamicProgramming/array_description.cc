#include <iostream>
#include <vector>

class Solution {
 public:
  static void Solve(int n, int m, std::vector<int> &v) {

    std::vector<std::vector<long long int>> dp(n + 1);
    for (int i = 0; i <= n; ++i) {
      dp[i].resize(m + 1);
    }

    if (v[0] == 0) {
      for (int i = 1; i <= m; ++i) {
        dp[0][i] = 1;
      }
    }
    else {
      dp[0][v[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {

      if (v[i] == 0) {
        for (int j = 1; j <= m; ++j) {
          dp[i][j] = dp[i - 1][j];
          if (j - 1 >= 0) {
            dp[i][j] += dp[i - 1][j - 1];
          }
          if (j + 1 <= m) {
            dp[i][j] += dp[i - 1][j + 1];
          }
          dp[i][j] %= kMOD;
        }
      }
      else {
        int j = v[i];
        dp[i][j] = dp[i - 1][j];
        if (j - 1 >= 0) {
          dp[i][j] += dp[i - 1][j - 1];
        }
        if (j + 1 <= m) {
          dp[i][j] += dp[i - 1][j + 1];
        }
        dp[i][j] %= kMOD;
      }
    }

    long long count = 0;
    if (v[n - 1] == 0){
      for (int i = 1; i <= m; ++i) {
        count += dp[n - 1][i];
        count %= kMOD;
      }
    }
    else {
      count = dp[n - 1][v[n - 1]];
    }

    std::cout << count;
  }
 private:
  static const long long int kMOD = 1e9 + 7;

};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> v(n);

  int x;
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    v[i] = x;
  }

  Solution::Solve(n, m, v);
};
