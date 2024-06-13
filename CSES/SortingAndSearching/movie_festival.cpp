#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>


bool ComparePairs(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
  return lhs.second < rhs.second;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int> > intervals;


  int start, end;
  for (int i = 0; i < n; i++) {
    std::cin >> start >> end;
    intervals.push_back(std::make_pair(start, end));
  }

  std::sort(intervals.begin(), intervals.end(), ComparePairs );

  int count = 1;
  end = intervals[0].second;
  for (int i = 1; i < n; i++) {
    if (intervals[i].first >= end) {
      end = intervals[i].second;
      count++;
    }
  }

  std::cout << count;
  
  return 0;
}



  
