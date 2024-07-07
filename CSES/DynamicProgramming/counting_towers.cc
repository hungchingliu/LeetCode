#include <iostream>
#include <vector>

class Solution {
 public:
  static const int kMOD = 1e9 + 7;
  static const int kMAXN = 1e6;

  static void Solve(int t, const std::vector<int> &queries) {

    std::vector<long long> dp_a(kMAXN);
    std::vector<long long> dp_b(kMAXN);

    for (int i = 0; i < t; ++i) {
      std::cout << CountingTowers(queries[i], dp_a, dp_b) << '\n';
    }

    return;
  }

  static long long CountingTowers(int n, std::vector<long long> &dp_a, std::vector<long long> &dp_b) {

    if (dp_a[n] != 0 && dp_b[n] != 0) {
      return (dp_a[n] + dp_b[n]) % kMOD;
    }

    if (n == 1) {
      dp_a[n] = 1;
      dp_b[n] = 1;
      return 2;
    }

    CountingTowers(n - 1, dp_a, dp_b);
    dp_a[n] = (4 * dp_a[n - 1] + dp_b[n - 1]) % kMOD;
    dp_b[n] = (dp_a[n - 1] + 2 * dp_b[n - 1]) % kMOD;

    return (dp_a[n] + dp_b[n]) % kMOD;
  }

};

int main() {
  int t;
  std::cin >> t;
  std::vector<int> queries(t);

  int n = 0;
  for (int i = 0; i < t; ++i) {
    std::cin >> n;
    queries[i] = n;
  }

  Solution::Solve(t, queries);
  return 0;
}
