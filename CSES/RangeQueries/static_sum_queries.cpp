#include <iostream>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;

  std::vector<unsigned long long> prefix_sum;
  prefix_sum.resize(n + 1);
  prefix_sum[0] = 0;

  int num;
  for (int i = 1; i <= n; i++) {
    std::cin >> num;
    prefix_sum[i] = prefix_sum[i - 1] + num;
  }
  
  int left, right;
  for (int i = 0; i < q; i++) {
    std::cin >> left >> right;
    unsigned long long int ans = prefix_sum[right] - prefix_sum[left - 1];
    std::cout << ans << std::endl;
  }

  return 0;
}
