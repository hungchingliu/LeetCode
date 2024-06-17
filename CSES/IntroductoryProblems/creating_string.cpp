#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

class Solution {
 public:
  void Solve(std::string s) {
    std::vector<bool> chosen(s.size() + 1, false);
    std::string permutation;
    std::set<std::string> answers;
    Permutation(permutation, s, chosen, answers);

    std::cout << answers.size() << std::endl;
    for (auto &ans: answers) {
      std::cout << ans << std::endl;
    }
    return;
  }

  void Permutation(std::string &permutation, std::string &s, std::vector<bool> &chosen, std::set<std::string> &answers) {

    if (permutation.size() == s.size()) {
      answers.insert(permutation);
    }

    for (int i = 0; i < s.size(); i++) {
      if (chosen[i]) {
        continue;
      }
      permutation += s[i];
      chosen[i] = true;
      Permutation(permutation, s, chosen, answers);
      permutation.pop_back();
      chosen[i] = false;
    }

  }

};

int main() {
  std::string s;
  std::cin >> s;

  std::sort(s.begin(), s.end());
  Solution().Solve(s);
  return 0;
}
