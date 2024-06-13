#include <iostream>
#include <cmath>


int main() {
  int n;
  int mod = pow(10, 9) + 7;
  std::cin >> n;

  int ans = 1;

  for (int i = 0; i < n; i++) {
    ans *= 2;
    if (ans > mod) {
      ans %= mod;
    }
  }

  std::cout << ans;

}
