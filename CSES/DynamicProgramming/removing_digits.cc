#include <iostream>
#include <vector>

class Solution {
 public:
  static void Solve(int n) {
    std::vector<int> dp(n + 1, -1);
    std::vector<bool> ready(n + 1, false);

    dp[0] = 0;

    Search(n, dp, ready);
    std::cout << dp[n];
    return;
  }
 private:
  static void Search(int n, std::vector<int> &dp, std::vector<bool> &ready) {
    if (n == 0) {
      return;
    }
    int num = n;
    int min_steps = -1;

    while (num) {
      int digit = num % 10;

      if (digit != 0) {
        if (!ready[n - digit]) {
          Search(n - digit, dp, ready);
        }

        if (min_steps == -1) {
          min_steps = dp[n - digit] + 1;
        } else {
          min_steps = std::min(min_steps, dp[n - digit] + 1);
        }
      }

      num /= 10;
    }

    dp[n] = min_steps;
    ready[n] = true;

    return;
  }
};

int main() {
  int n;
  std::cin >> n;
  Solution::Solve(n);

  return 0;
};


