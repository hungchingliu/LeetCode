#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
 public:
  void Solve(int n){
    std::vector<std::string> gray_code;

    gray_code.push_back("0");
    gray_code.push_back("1");

    for (int i = 2; i <= n; i++) {
      Increment(gray_code);
    }

    for(std::string &s: gray_code) {
      std::cout << s << std::endl;
    }
    return;
  }

  void Increment(std::vector<std::string> &gray_code) {

    std::vector<std::string> zero_prefix;
    std::vector<std::string> one_prefix;

    for (std::string s: gray_code) {
      zero_prefix.push_back("0" + s);
      one_prefix.push_back("1" + s);
    }

    std::reverse(one_prefix.begin(), one_prefix.end());
    zero_prefix.insert(zero_prefix.end(), one_prefix.begin(), one_prefix.end());
    gray_code = zero_prefix;
    return;
  }


};

int main() {
  int n;
  std::cin >> n;

  Solution().Solve(n);
}
