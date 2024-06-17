#include <iostream>
#include <vector>
#include <limits>


class Solution {
 public:
  void Solve(std::vector<int> &apples) {

    long long int min_diff = std::numeric_limits<long long int>::max();
    ProcessSubset(apples, 0, 0, 0, min_diff);

    std::cout << min_diff;
    return;
  }

  void ProcessSubset(std::vector<int> &apples, int index, long long int sum1, long long int sum2, long long int &min_diff) {

    if (index == apples.size()) {
      if (sum2 > sum1) {
        std::swap(sum1, sum2);
      }
      min_diff = std::min(min_diff, sum1 - sum2);
      return;
    }

    ProcessSubset(apples, index + 1, sum1 + apples[index], sum2, min_diff);
    ProcessSubset(apples, index + 1, sum1, sum2 + apples[index], min_diff);

    return;
  }


};

int main() {
  int n;
  std::cin >> n;

  std::vector<int> apples;
  apples.resize(n);

  int a;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    apples[i] = a;
  }

  Solution().Solve(apples);

} 


