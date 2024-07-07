#include <iostream>
#include <vector>

// 5 1 3 2 4 6 7
// 1
// 1
// 2
//

class Solution {
 public:
  static void Solve(int n, const std::vector<int> &numbers) {
    std::vector<int> dp(n);
    int lis = 0; 

    for (int i = 0; i < n; ++i) {
      int is = 0;
      for (int j = 0; j < i; ++j) {
        if (numbers[j] < numbers[i] && dp[j] > is) {
          is = dp[j];
        }
      }
      dp[i] = is + 1;
      lis = std::max(lis, dp[i]);
    }

    std::cout << lis;
    return;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  int number;
  for (int i = 0; i < n; ++i) {
    std::cin >> number;
    numbers[i] = number;
  }

  Solution::Solve(n, numbers);
}
