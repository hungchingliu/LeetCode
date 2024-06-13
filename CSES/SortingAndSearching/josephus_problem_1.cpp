#include <iostream>
#include <list>

int main() {
  int n;
  std::cin >> n;

  std::list<int> childrens;
  std::list<int> remove_order;

  
  for (size_t i = 1; i <= n; i++) {
    childrens.push_back(i);
  }

  // Game start
  int gap = 1;
  auto it = childrens.begin();

  while (childrens.size() != 0) {
    for (int i = 0; i < gap; i++) {
      it++;
      if (it == childrens.end()) {
        it = childrens.begin();
      }
    }

    int index = *it;
    remove_order.push_back(index);
    it = childrens.erase(it);
    if (it == childrens.end()) {
      it = childrens.begin();
    }
  }


  for (auto index: remove_order) {
    std::cout << index << " ";
  }
  return 0;
}
