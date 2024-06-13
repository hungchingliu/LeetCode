#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    int x;
    std::cin >> n >> x;

    std::vector<int> child(n, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> child[i];
    }

    std::sort(child.begin(), child.end());

    int left_index = 0;
    int right_index = n - 1;

    int count = 0;

    while (left_index < right_index - 1) { 
        int heavy_child = child[right_index];
        int light_child = child[left_index];

        if ( x - heavy_child >= light_child) {
            right_index--;
            left_index++;
        }
        else {
            right_index--;
        }
        count++;
    }


    if (left_index == right_index) {
        count++;
    }
    else {
        int heavy_child = child[right_index];
        int light_child = child[left_index];

        if ( x - heavy_child >= light_child) {
            count++;
        }
        else {
            count += 2;
        }
    }

    std::cout << count;
}

