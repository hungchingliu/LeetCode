#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  static void Solve(int n, const std::vector<int> &coins) {
    std::vector<int> dp(n + 1, -1);

    for (int coin: coins) {
      if(coin <= n) {
        dp[coin] = 1;
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int coin: coins) {
        if (i - coin >= 0 && dp[i - coin] != -1) {
          if (dp[i] == -1) {
            dp[i] = dp[i - coin] + 1;
          } else {
            dp[i] = std::min(dp[i], dp[i - coin] + 1);
          }
        }
      }
    }

    std::cout << dp[n];
    return;
  }
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
}
