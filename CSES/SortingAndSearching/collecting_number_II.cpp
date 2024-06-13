#include <iostream>
#include <vector>

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  
  std::vector<int> numbers;
  std::vector<int> indices;
  numbers.resize(n + 1);
  indices.resize(n + 1);

  int number;

  for (int i = 1; i <= n; i++) {
    std::cin >> number;
    numbers[i] = number;
    indices[number] = i;
  }

  int count = 1;

  for (int i = 2; i <= n; i++) {
    if (indices[i] < indices[i - 1]) {
      count++;
    }
  }

  int a, b;

  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;

    if (a == b) {
      std::cout << count << std::endl;
      continue;
    }

    int number_a = numbers[a];
    int number_b = numbers[b];

    if (number_a > number_b) {
      std::swap(number_a, number_b);
      std::swap(a, b);
    }

    if (number_a - 1 > 0) {
      int prev_index = indices[number_a - 1];
      if (a > prev_index && b < prev_index) {
        count++;
      }
      else if (a < prev_index && b > prev_index) {
        count--;
      }
    }

    if (number_a + 1 == number_b) {
      if (a > b) {
        count--;
      }
      else {
        count++;
      }
    }
    else {
      int next_index = indices[number_a + 1];

      if (next_index > a && next_index < b) {
        count++;
      }
      else if (next_index < a && next_index > b) {
        count--;
      }

      int prev_index = indices[number_b - 1];

      if (prev_index < b && prev_index > a) {
        count++; 
      }
      else if (prev_index > b && prev_index < a) {
        count--;
      }
    }

    if (number_b + 1 <= n) {
      int next_index = indices[number_b + 1];

      if (next_index > b && next_index < a) {
        count++;
      }
      else if (next_index < b && next_index > a) {
        count--;
      }
    }

    std::swap(indices[number_a], indices[number_b]);
    std::swap(numbers[a], numbers[b]);

    std::cout << count << std::endl;
  }

  return 0;
}

// 4 2 1 5 3
// 3 2 5 1 4
//
// 4 1 2 5 3
// 2 3 5 1 4
//
// 3 1 2 5 4
// 2 3 1 5 4
