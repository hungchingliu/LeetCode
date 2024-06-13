#include<iostream>
#include<vector>
#include<algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> numbers;

  int number;
  for (int i = 0; i < n; i++) {
    std::cin >> number;
    numbers.push_back(number);
  }

  long long int max_sum = numbers[0]; 
  long long int max_sum_ends_here = numbers[0]; 

  for (int i = 1; i < n; i++) {
    max_sum_ends_here = std::max(max_sum_ends_here + numbers[i], static_cast<long long int>(numbers[i]));
    max_sum = std::max(max_sum_ends_here, max_sum);
  }

  std::cout << max_sum;
  
  return 0;
}

