#include <iostream>
#include <set>

int main () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int x;
  int n;
  std::cin >> x >> n;
  std::set<int> lights;
  lights.insert(0);
  lights.insert(x);
  std::multiset<int> lengths;
  lengths.insert(x);

  int p;
  for (int i = 0; i < n; i++) {
    std::cin >> p;
    lights.insert(p);
  
    auto it = lights.find(p);
    auto prev_it = std::prev(it);
    auto next_it = std::next(it);

    int left = *prev_it;
    int right = *next_it;

    auto lengths_it = lengths.find(right - left);
    lengths.erase(lengths_it);
    lengths.insert(p - left);
    lengths.insert(right - p);

    lights.insert(p);

    auto const_lengths_it = lengths.crbegin();
    std::cout << *const_lengths_it << " ";
  }

  return 0;

}
