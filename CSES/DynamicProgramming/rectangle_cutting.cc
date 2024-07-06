#include <iostream>
#include <vector>

class Solution {
 public:
  static void Solve(int a, int b) {
    if (a > b) {
      std::swap(a, b);
    }
    std::vector<std::vector<int>> memoization(b + 1);
    for (int i = 0; i <= b; ++i) {
      memoization[i].resize(b + 1);
    }

    std::cout << Search(a, b, memoization);
    return;
  }
 private:
  static int Search(int a, int b, std::vector<std::vector<int>> &memoization) {
    if (a == b) {
      return 0;
    }
    if (memoization[a][b] == 0) {
      int min = -1;
      for (int i = 1; i < a; ++i) {
        if (min == -1) {
          min = Search(i, b, memoization) + Search(a - i, b, memoization) + 1;
        } else {
          min = std::min(min, Search(i, b, memoization) + Search(a - i, b, memoization) + 1);
        }
      }

      for (int i = 1; i < b; ++i) {
        if (min == -1) {
          min = Search(a, i, memoization) + Search(a, b - i, memoization) + 1;
        } else {
          min = std::min(min, Search(a, i, memoization) + Search(a, b - i, memoization) + 1);
        }
      }
      memoization[a][b] = min;
    }
    return memoization[a][b];
  }
};

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a, b;
  std::cin >> a >> b;
  Solution::Solve(a, b);
  return 0;
}
