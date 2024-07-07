#include <iostream>
#include <vector>

class Solution {
 public:
  static const int kMOD = 1e9 + 7;
  static void Solve(int n) {
    int target = (1 + n) * n / 2;
    long long count = 0;

    if(target % 2 == 0) {
      target /= 2;
    } else {
      std::cout << "0";
      return;
    }

    count = KnapStack(n, target, n);

    std::cout << count;

    return;
  }

  static long long KnapStack(int n, int target, int exclude) {

    std::vector<long long> dp(target + 1);
    dp[0] = 1;

    for (int weight = 1; weight <= n; ++weight) {
      if (weight == exclude) {
        continue;
      }
      for (int sum = target; sum >= 0; --sum) {
        if (sum - weight >= 0) {
          dp[sum] += dp[sum - weight];
          dp[sum] %= kMOD;
        }
      }

    }
    return dp[target];
  }

};

int main() {
  int n;
  std::cin >> n;
  Solution::Solve(n);
  return 0;
}
