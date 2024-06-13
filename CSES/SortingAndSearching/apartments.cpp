#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    int m;
    int k;

    std::cin >> n >> m >> k;

    std::vector<int> applicants(n, 0);
    std::vector<int> apartments(m, 0);

    for(int i = 0; i < n; i++) {
        std::cin >> applicants[i];
    }

    for(int i = 0; i < m; i++) {
        std::cin >> apartments[i];
    }

    std::sort(applicants.begin(), applicants.end());
    std::sort(apartments.begin(), apartments.end());

    int applicant_index = 0;
    int apartment_index = 0;

    int fit_count = 0;
    
    while(static_cast<std::vector<int>::size_type>(applicant_index) < applicants.size() && 
          static_cast<std::vector<int>::size_type>(apartment_index) < apartments.size()) {
        int applicant = applicants[applicant_index];
        int lower_bound = applicant - k;
        int upper_bound = applicant + k;
        int apartment = apartments[apartment_index];

        if(apartment < lower_bound) {
            apartment_index++;
        }
        else if(apartment >= lower_bound && apartment <= upper_bound) {
            fit_count++;
            applicant_index++;
            apartment_index++;
        }
        else {
            applicant_index++;
        }
    }

    std::cout << fit_count;
    
    return 0;
}
