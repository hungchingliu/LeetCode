#include <iostream>

class Solution {
 public:
   void Solve(long long int k) {
     long long int count = 0;

     if (k == 1){
       std::cout << "0" << std::endl;
       return;
     }
     
     if (k == 2) {
       std::cout << "6" << std::endl;
       return;
     }
     count = 4 * 2 + 8 * 3 + (4 * k - 12) * 4 + (4 * k - 16) * 6 + (k * k - (4 + 8 + 8 * k - 28)) * 8;
     std::cout << (k * k * (k * k - 1) - count) / 2 << std::endl;
     return;
   }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int k;


  std::cin >> k;

  for (int i = 1; i <= k; i++) {
    Solution().Solve(i);
  }


  return 0;
}
