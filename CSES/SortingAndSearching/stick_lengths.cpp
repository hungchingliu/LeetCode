#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> sticks;

  sticks.resize(n);

  for (int& stick_length: sticks) {
    std::cin >> stick_length;
  }

  std::sort(sticks.begin(), sticks.end());

  long long int median = static_cast<long long int>(sticks[n / 2]);  
  long long int operations = 0;

  for (int i = 0; i < n; i++) {
    operations += std::abs(median - sticks[i]);
  }

  std::cout << operations;

  return 0;
}
