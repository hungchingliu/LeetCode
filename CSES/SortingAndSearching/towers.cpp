#include <iostream>
#include <vector>
#include <set>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> plates;
  plates.resize(n);

  for (int& plate: plates) {
    std::cin >> plate;
  }
    
  int count = 0;
  std::multiset<int> tower_tops;


  for (int i = 0; i < n; i++) {
    int plate = plates[i];
    auto it = tower_tops.upper_bound(plate);
    if (it != tower_tops.end()) {
      tower_tops.erase(it);
      tower_tops.insert(plate);
    }
    else {
      tower_tops.insert(plate);
      count++;
    }
  }
  std::cout << count;

  return 0;
}
