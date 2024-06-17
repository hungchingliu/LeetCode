#include <iostream>
#include <vector>

class Solution {
 public:
   void Solve(int n) {
     std::vector<std::pair<int, int>> operations;

     Hanoi(n, 1, 3, operations);

     std::cout << operations.size() << std::endl;
     for (std::pair<int, int> operation: operations) {
       std::cout << operation.first << " " << operation.second << std::endl;
     }
     return;
   }
   void Hanoi(int n, int source, int target, std::vector<std::pair<int, int>> &operations) {
     if (n == 1) {
       operations.push_back({source, target});
       return;
     }

     int temp;

     temp = 6 - source - target;

     Hanoi(n - 1, source, temp, operations);
     operations.push_back({source, target});
     Hanoi(n - 1, temp, target, operations);

   }
};

int main() {
  int n;
  std::cin >> n;

  Solution().Solve(n);
  return 0;
}
