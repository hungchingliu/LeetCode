#include <iostream>
#include <vector>
#include <algorithm>

// {0} {1}
// {0, 1} {1, 2}
// {0, 1, 2} 
int main() {
  int n;
  std::cin >> n;
  std::vector<unsigned int> coins;
  coins.resize(n);

  for (unsigned int& coin: coins) {
    std::cin >> coin;
  }

  std::sort(coins.begin(), coins.end());

  unsigned long long max_available = 0;

  bool found = false;
  unsigned long long smallest_missing_sum;

  for (int i = 0; i < n; i++) {
    if (coins[i] <= max_available + 1) {
      max_available += coins[i];
    }
    else {
      smallest_missing_sum = max_available + 1;
      found = true;
      break;
    }
  }

  if(!found){
    smallest_missing_sum = max_available + 1;
  }

  std::cout << smallest_missing_sum;

  return 0;
}
      

  
