#include <iostream>
#include <vector>

class Solution {
 public:
  static void Solve(int x, const std::vector<int> &coins) {
    std::vector<int> dp(x + 1);
    dp[0] = 1;

    for (int i = 1; i <= x; ++i) {
      for (int coin: coins) {
        if (i - coin >= 0) {
          dp[i] += dp[i - coin];
          dp[i] %= kMOD;
        }
      }
    }

    std::cout << dp[x];
  }
 private:
  static const int kMOD = 1e9 + 7;
};

int main() {
  int n, x;
  std::cin >> n >> x;

  std::vector<int> coins(n);

  int c;
  for (int i = 0; i < n; ++i) {
    std::cin >> c;
    coins[i] = c;
  }

  Solution::Solve(x, coins);
  return 0;
};
