#include <iostream>

class Solution {
 public:
   long long int Solve(long long int x, long long int y) {
     long long int base = 0;

     if (x > y) {
       base = (x - 1) * (x - 1);
       if ((x - 1) % 2 == 0) {
         base += y;
       }
       else {
         base += 2 * (x - 1) + 1 - (y - 1);
       }
     }
     else {
       base = (y - 1) * (y - 1); 
       if ((y - 1) % 2 == 1) {
         base += x;
       }
       else {
         base += 2 * (y - 1) + 1 - (x - 1);
       }
     }

     return base;
   }

};

int main() {
  int t;
  std::cin >> t;

  Solution solution;

  int x, y;
  for (int i = 0; i < t; i++) {
    std::cin >> x >> y;
    std::cout << solution.Solve(x, y) << std::endl;
  }
  return 0;
}
