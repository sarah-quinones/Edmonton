#include "../../Headers/Edmonton.hpp"
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool isPermutation(int a, int b) {
	string s1 = to_string(a);
	string s2 = to_string(b);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return (s1 == s2);
}

// For this problem we need to find the other 4 digit numbers with same difference between primes.
int main(int argc, char *argv[]) {
	// The vector will hold all primes for us, so we don't need to check if a given number is a prime.
	vector<int> primes = Edmonton::generatePrimes<int>(10000);
	// Iterate through the primes.
	for(int i = 0; i < primes.size(); i++) {
		for(int j = i + 1; j < primes.size(); j++) {
			int k = primes[j] + primes[j] - primes[i];
			// If they are permutation we can check the next number as well.
			if(isPermutation(primes[i], primes[j])) {
				if(isPermutation(primes[i], k)) {
					// Find the diff + primes[j] in the vector, else skip.
					if(find(primes.begin(), primes.end(), k) != primes.end()) {
						cout << primes[i] << primes[j] << k << endl;
					} else {
						break;
					}
				}
			}
		}
	}
	return 0;
}