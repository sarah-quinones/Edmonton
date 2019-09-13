#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) 
{
    auto num_to_factor = 600'851'475'143;

    // Using a set so we can only keep the unique prime factors.
    set<int> prime_factors;

    // First prime factor is a 2, the only even prime, so divide number until we are left with an odd number.
    while(num_to_factor % 2 == 0) {
        prime_factors.insert(2);
        num_to_factor /= 2;
    }

    // Remaining prime factors are odd numbers from 3 to sqrt(n), not n/2.
    for(int i = 3; i <= sqrt(num_to_factor); i += 2) {
        while(num_to_factor % i == 0) {
            prime_factors.insert(i);
            num_to_factor /= i;
        }
    }

    // Anything left is the final prime factor.
    if(num_to_factor > 2) {
        prime_factors.insert(num_to_factor);
    }
    
    // Print largest item in the set.
    cout << *prime_factors.rbegin() << endl;
    return 0;
}