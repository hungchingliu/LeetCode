#include <iostream>


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    long long n;
    std::cin >> n;

    std::cout << n;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            std::cout << " " << n;
        }
        else {
            n = n * 3 + 1;
            std::cout << " " << n;
       }
    } 
    return 0;
}




