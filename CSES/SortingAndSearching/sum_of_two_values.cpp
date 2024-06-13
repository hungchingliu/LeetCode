#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

bool Compare_Pair(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
  return lhs.first < rhs.first;
}

int main() {
  int n;
  int x;
  
  std::cin >> n >> x;

  std::vector<std::pair<int, int> > numbers;

  int number;
  for (int i = 1; i <= n; i++) {
    std::cin >> number;
    std::pair<int, int> p = std::make_pair(number, i);
    numbers.push_back(p);
  }

  std::sort(numbers.begin(), numbers.end(), Compare_Pair);

  int left_ptr = 0;
  int right_ptr = numbers.size() - 1;
  
  while (left_ptr < right_ptr) {
    if (numbers[left_ptr].first + numbers[right_ptr].first == x) {
      if (numbers[left_ptr].second < numbers[right_ptr].second) {
        std::cout << numbers[left_ptr].second << " " << numbers[right_ptr].second;
      }
      else {
        std::cout << numbers[right_ptr].second << " " << numbers[left_ptr].second;
      }
      return 0;
    } else if (numbers[left_ptr].first + numbers[right_ptr].first < x) {
      left_ptr++;
    } else {
      right_ptr--;
    }
  }

  std::cout << "IMPOSSIBLE";
  
  return 0;
}
