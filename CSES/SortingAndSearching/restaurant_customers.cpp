#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

int main() {
  int n;
  std::cin >> n;

  int a, b;

  std::vector<std::pair<int, bool> > event_queue;

  for (int i = 0; i < n; i++) {
    std::cin >> a >> b;
    event_queue.push_back(std::make_pair(a, true));
    event_queue.push_back(std::make_pair(b, false));
  }

  std::sort(event_queue.begin(), event_queue.end());

  int max_people = 0;
  int count = 0;

  for (int i = 0; i < 2 * n; i++) {
    count += event_queue[i].second ? 1 : -1;
    max_people = std::max(count, max_people);
  }

  std::cout << max_people;
  return 0;
}




