#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> indices;
  indices.resize(n + 1);
  
  int number;
  for (int i = 0; i < n; i++) {
    std::cin >> number;
    indices[number] = i;
  }

  int count = 1;

  for (int i = 2; i <= n; i++) {
    if (indices[i] < indices[i - 1]) {
      count++;
    }
  }

  std::cout << count;
  return 0;
}


    
