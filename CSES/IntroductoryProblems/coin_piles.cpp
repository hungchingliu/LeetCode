#include <iostream>
#include <algorithm>


bool CheckLegalPiles(int a, int b) {
  if (a > b) {
    std::swap(a, b);
  }

  int diff = b - a;

  if (diff > a) {
    return false;
  }

  a -= diff;

  if (a % 3 == 0) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  int t;
  std::cin >> t;
  int a, b;

  for (int i = 0; i < t; i++) {

    std::cin >> a >> b;
    bool legal = CheckLegalPiles(a, b);
    if (legal) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
  
}
