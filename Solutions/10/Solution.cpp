#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

// When checking for prime numbers we only need to go till sqrt(n).
constexpr bool is_prime(long n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Put everything in vector and stop when we hit 2,000,000 on current integer. 
    vector<long> primes;
    long i = 2;
    while(i < 2'000'000) {
        if(is_prime(i++)) {
            primes.push_back(i - 1);
        }
    }
    // Auto sum up result and print it for us.
    cout << accumulate(primes.begin(), primes.end(), (long)0) << endl;
    return 0;
}