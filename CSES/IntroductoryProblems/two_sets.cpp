#include <iostream>
#include <vector>

class Solution {
  public:
    void Solve(int n) {
      if (n % 4 == 1 || n % 4 == 2) {
        std::cout << "NO";
        return;
      }
      std::vector<int> set_1;
      std::vector<int> set_2;

      if (n % 4 == 3 || n % 4 == 0) {

        bool insert_set_1 = true;
        for (int i = 1; i <= n; i++) {
          if (insert_set_1) {
            set_1.push_back(i);
          } else {
            set_2.push_back(i);
          }

          if (i == n/2) {
            continue;
          } else {
            insert_set_1 = !insert_set_1;
          }
        }

      }

      std::cout << "YES" << std::endl;
      std::cout << set_1.size() << std::endl;
      for (int i = 0; i < set_1.size(); i++) {
        std::cout << set_1[i] << " ";
      }
      std::cout << std::endl;
      std::cout << set_2.size() << std::endl;
      for (int i = 0; i < set_2.size(); i++) {
        std::cout << set_2[i] << " ";
      }

      return;
    }
};

int main() {
  int n;
  std::cin >> n;
  Solution().Solve(n);
  return 0;
}
