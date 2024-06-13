#include <iostream>

int main () {
    int n; 
    std::cin >> n;

    int num;
    long long moves = 0;
    int last_element;
    std::cin >> last_element;

    for (int i = 1; i < n; i++) {
        std::cin >> num;
        if (num < last_element) {
            moves += last_element - num;
        }
        else {
            last_element = num;
        }
    }

    std::cout << moves;
}
        
        

