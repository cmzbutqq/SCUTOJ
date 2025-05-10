#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   
#include <set>       



long calculate_gcd(long a, long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    if (a == 0 && b == 0) {
        return 0; 
    }
    return a;
}



int main() {

    long n;
    std::cin >> n;

    std::vector<long> a(n);
    for (long i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    a.erase(std::unique(a.begin(), a.end()), a.end());

    long m = a.size(); 

    if (m <= 1) {
        std::cout << n << std::endl;
        return 0;
    }

    long min_val = a[0];
    long max_val = a[m - 1];


    long common_difference = 0;

    for (long i = 1; i < m; ++i) {
        long diff = a[i] - a[i-1];
        common_difference = calculate_gcd(common_difference, diff);
    }
    

    long num_terms = (max_val - min_val) / common_difference + 1;

    std::cout << num_terms << std::endl;

    return 0;
}