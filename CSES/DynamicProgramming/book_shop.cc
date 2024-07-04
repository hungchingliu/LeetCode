#include <iostream>
#include <vector>

class Solution {
 public:
  static void Solve(int n, int x, const std::vector<int> &prices, const std::vector<int> &pages) {
    std::vector<long long> dp(x + 1, 0);

    for (int book = 0; book < n; ++book) {
      for (int i = x; i >= 0; --i) {
        if (i - prices[book] >= 0) {
          dp[i] = std::max(dp[i], dp[i - prices[book]] + pages[book]);
        }
      }
    }

    std::cout << dp[x];
    return;
  }

};

int main() {
  int n, x;
  std::cin >> n >> x;

  std::vector<int> prices;
  std::vector<int> pages;

  prices.resize(n);
  pages.resize(n);

  int h;
  for (int i = 0; i < n; ++i) {
    std::cin >> h;
    prices[i] = h;
  }

  int s;
  for (int i = 0; i < n; ++i) {
    std::cin >> s;
    pages[i] = s;
  }
  
  Solution::Solve(n, x, prices, pages);
  return 0;
};
