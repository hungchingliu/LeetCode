#include <iostream>
#include <array>

class Solution {
 public:
   static void Solve(int n) {
     std::array<int, kMAX_N + 1> dp{0};
     dp[0] = 1;
     for (int i = 1; i <= n; ++i) {
       for (int dice = 1; dice <= 6; ++dice) {
         if (i - dice >= 0) {
           dp[i] += dp[i - dice];
           dp[i] %= kMOD;
         }
       }
     }

     std::cout << dp[n];
     return;
   }
 private:
   static const int kMOD = 1e9 + 7;
   static const int kMAX_N = 1e6;

};

int main() {
  int n;
  std::cin >> n;
  Solution::Solve(n);
  return 0;
};
