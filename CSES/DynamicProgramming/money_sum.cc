#include <iostream>
#include <array>
#include <vector>

class Solution {
 public:
  static void Solve(int n, const std::vector<int> &coins) {
    std::array<bool, 100001> dp = {false};
  
    dp[0] = true;
    for (int coin: coins) {
      for (int i = 100000; i >= 0; --i) {
        if (i - coin >= 0) {
          dp[i] = dp[i] || dp[i - coin];
        }
      }
    }

    int count = 0;

    for (int i = 1; i <= 100000; ++i) {
      if (dp[i]) {
        ++count;
      }
    }

    std::cout << count << '\n';

    for(int i = 1; i <= 100000; ++i) {
      if (dp[i]) {
        std::cout << i << " ";
      }
    }

    return;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> coins(n);
  int c;
  for (int i = 0; i < n; ++i) {
    std::cin >> c;
    coins[i] = c;
  }

  Solution::Solve(n, coins);
  return 0;
};
