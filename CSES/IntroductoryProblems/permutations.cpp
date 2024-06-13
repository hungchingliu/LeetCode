#include <iostream>

int main () {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 1;
    }
    else if (n < 4) {
        std::cout << "NO SOLUTION";
    }
    else {
        bool init = false;
        int num = n;
        if ( num%2 == 0){
            num--;
        }

        while (num > 0) {
            if (!init) {
                std::cout << num;
                init = true;
            }
            else {
                std::cout << " " << num;
            }
            num -= 2;
        }
        num = n;

        if ( num%2 == 1){
            num--;
        }

        while (num > 0) {
            std::cout << " " << num;
            num -= 2;
        }
    }

    return 0;
}



        
