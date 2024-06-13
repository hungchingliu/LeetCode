#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int result = 0;

    int num = 0;

    for (int i = 1; i <= n - 1; i++) {
        std::cin >> num; 
        result ^= num;
        result ^= i;
    }

    result ^= n;

    std::cout << result;

    return 0;
}

