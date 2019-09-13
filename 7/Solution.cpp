#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// When checking for prime numbers we only need to go till sqrt(n).
constexpr bool is_prime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Put everything in vector and stop when the size is 10001. Initalized with a 2 so we can just keep it done.   
    vector<int> primes;
    int i = 2;
    while(primes.size() != 10'001) {
        if(is_prime(i++)) {
            primes.push_back(i - 1);
        }
    }
    cout << primes[primes.size() - 1] << endl;
    return 0;
}