#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::vector<int> num_array;
    int num;

    std::cin >> n;

    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        num_array.push_back(num);
    }

    std::sort(num_array.begin(), num_array.end());

    int distinct_count = 1;

    for (int i = 1; i < n; i++) {
        if (num_array[i] != num_array[i - 1]) {
            distinct_count++;
        }
    }

    std::cout << distinct_count;
    return 0;
}




