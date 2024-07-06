#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  static void Solve(int n, const std::vector<int> &numbers) {
    std::vector<std::vector<long long>> dp_first(n + 1);
    std::vector<std::vector<long long>> dp_second(n + 1);
    std::vector<long long> prefix_sum(n + 1);

    for (int i = 1; i <= n; ++i) {
      prefix_sum[i] = prefix_sum[i - 1] + numbers[i];
    }
    
    for (int i = 0; i <= n; ++i) {
      dp_first[i].resize(n + 1);
      dp_second[i].resize(n + 1);
    }


    for (int i = 0; i <= n; ++i) {
      for (int j = 1; j <= n - i; ++j) {
        int left = j;
        int right = j + i;

        if (left == right) {
          dp_first[left][right] = numbers[left];
          dp_second[left][right] = 0;
        }
        else {
          dp_first[left][right] = std::max(dp_second[left + 1][right] + numbers[left], dp_second[left][right - 1] + numbers[right]);
          dp_second[left][right] = prefix_sum[right] - prefix_sum[left - 1] - dp_first[left][right];
        }
      }
    }

    std::cout << dp_first[1][n];
    return;
  } 
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers(n + 1);

  int number;
  for (int i = 1; i <= n; ++i) {
    std::cin >> number;
    numbers[i] = number;
  }

  Solution::Solve(n, numbers);
  return 0;
}


