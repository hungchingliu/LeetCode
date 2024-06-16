#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
 public:
  void Solve(std::string s) {
    std::vector<int> char_count;
    char_count.resize(26);

    for (auto &c: s) {
      char_count[c - 'A']++;
    }

    int odd_count = 0;
    int odd_char_index = -1;
    for (int i = 0; i < 26; i++) {
      if (char_count[i] % 2 != 0){
        odd_count++;
        odd_char_index = i;
      }
    }

    if (odd_count > 1) {
      std::cout << "NO SOLUTION";
    }
    else {
      std::string output;
      for(int i = 0; i < 26; i++) {
        if (i == odd_char_index) {
          continue;
        }
        for (int j = 0; j < char_count[i] / 2; j++) {
          output += std::string(1, char('A' + i));
        }
      }
      std::string output_reverse = output; 
      std::reverse(output_reverse.begin(), output_reverse.end());
      if(odd_count) {
        for (int i = 0; i < char_count[odd_char_index]; i++) {
          output += std::string(1, char('A' + odd_char_index));
        }
      }

      output += output_reverse;
      std::cout << output;
    }
    return;
  }
};

int main() {
  std::string s;
  std::cin >> s;

  Solution().Solve(s);
  return 0;
}
