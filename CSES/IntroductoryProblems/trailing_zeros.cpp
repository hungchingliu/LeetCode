#include <iostream>

int main() {

    int n;
    int count = 0;
    int factor = 5;
    std::cin >> n;

    while (factor <= n) {
        count += n / factor;
        factor *= 5;
    }
    std::cout << count;

    return 0;
}
