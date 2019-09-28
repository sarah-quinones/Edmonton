#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
Can just brute-force this in a fairly straight-forward based manner. Just need to take care to use larger numbers.
*/
constexpr unsigned int genVal(unsigned int a, unsigned int b, unsigned int c) {
	return (a * a) + (b * b * b) + (c * c * c * c);
}

int main(int argc, char *argv[]) {
	// Only have to go upto the roots of 50 million.
	vector<unsigned int> primes = Edmonton::generatePrimes<unsigned int>(7081);
	vector<int> created(50'000'000, 0);
	// Mark everything off in the vector if we create it.
	for(int i = 0; i < primes.size(); i++) {
		for(int j = 0; j < 75; j++) {	 // 367 is the 74th prime.
			for(int k = 0; k < 25; k++) { // 83 is the 24th prime.
				auto val = genVal(primes[i], primes[j], primes[k]);
				if(val >= 50'000'000) {
					break;
				}
				created[val] = 1;
			}
		}
	}
	auto res = accumulate(created.begin(), created.end(), 0);
	cout << res << endl;
	return 0;
}