#include<iostream>
#include<set>

int main() {
    int n;
    int m;
    std::cin >> n >> m;

    std::multiset<int, std::greater<int> > tickets;

    int number;
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        tickets.insert(number);
    }

    std::multiset<int>::iterator it;
    for (int i = 0; i < m; i++) {
        std::cin >> number;
        it = tickets.lower_bound(number);
        if(it != tickets.end()) {
            std::cout << *it << std::endl;
            tickets.erase(it);
        }
        else {
            std::cout << "-1" << std::endl;
        }
    }

    return 0;
}

