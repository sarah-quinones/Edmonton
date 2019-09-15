#include <iostream>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

constexpr bool isPentagonal(long long x) {
    double n = (1 + sqrt(24 * x + 1)) / 6;
    return n == (long long) n;
}

// Generate the n'th pentagonal number.
constexpr long long pentagonal(long long n) {
    return (n * ((3 * n) - 1)) / 2;
}

int main(int argc, char* argv[]) {
    // Generate the first 1000 pentagonal numbers and put them into a set.
    set<long long> pentaNums;
    for(long long n = 1; n <= 5000; n++) {
        pentaNums.emplace(pentagonal(n));
    }
    // Loop through the pentagonal numbers and find the sum and differences, and check if they are valid.
    long long D = LONG_LONG_MAX;
    for(const auto& j : pentaNums) {
        for(const auto& k : pentaNums) {
            if(isPentagonal(j + k) && isPentagonal(abs(k - j))) {
                D = min(D, abs(k - j));
            }
        }
    }
    cout << D << endl;
    return 0;
}