#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


struct Range {
  int left;
  int right;
  int index;
};

bool CompareRange(const Range &lhs, const Range &rhs) {
  return lhs.left == rhs.left ? lhs.right > rhs.right : lhs.left < rhs.left;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<Range> ranges;
  std::vector<bool> contains_other_ranges;
  std::vector<bool> contained_by_other_ranges;

  contains_other_ranges.resize(n);
  contained_by_other_ranges.resize(n);

  int left;
  int right;

  for (int i = 0; i < n; i++) {
    std::cin >> left >> right;
    Range range;
    range.left = left;
    range.right = right;
    range.index = i;
    ranges.push_back(range);
  }

  std::sort(ranges.begin(), ranges.end(), CompareRange);

  int max_right = ranges[0].right;

  for (int i = 1; i < n; i++) {
    if (ranges[i].right <= max_right) {
      contained_by_other_ranges[ranges[i].index] = true;
    } else {
      contained_by_other_ranges[ranges[i].index] = false;
      max_right = ranges[i].right;
    }
  }

  int min_right = ranges[n - 1].right;

  for (int i = n - 2; i >= 0; i--) {
    if (ranges[i].right >= min_right) {
      contains_other_ranges[ranges[i].index] = true;
    } else {
      contains_other_ranges[ranges[i].index] = false;
      min_right = ranges[i].right;
    }
  }
  for (auto const &contains: contains_other_ranges) {
    std::cout << contains << " ";
  }

  std::cout << std::endl;

  for (auto const &contained: contained_by_other_ranges) {
    std:: cout << contained << " ";
  }

  return 0;
}

