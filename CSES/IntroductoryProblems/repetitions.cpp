#include <string>
#include <iostream>


int main() {
    std::string sequence;
    std::cin >> sequence;

    int max_repetitions = 1;
    int count = 1;
    for (int i = 1; i < sequence.length(); i++) {
        if (sequence[i] == sequence[i - 1]) {
            count++;
        }
        else {
            if (count > max_repetitions) {
                max_repetitions = count;
            }
            count = 1;
        }
    }
    
    if (count > max_repetitions) {
        max_repetitions = count;
    }

    std::cout << max_repetitions;
    return 0;
}
        

