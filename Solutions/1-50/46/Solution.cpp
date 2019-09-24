#include "../../Headers/Debug.hpp"
#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

/* 
Can bruteforce this problem fairly easily by just generating a vector and looping through it, 
finding the first odd number that was not flagged and outputting it. 
*/
int main(int argc, char *argv[]) {
	// Just a quick guess that the first number should be somewhere low.
	vector<int> primes = Edmonton::generatePrimes<int>(10000);
	// Will hold vector that we can flag numbers with.
	vector<bool> composites(100'000, false);
	// Brute-force everything. First loop is for the primes.
	// Second group is for the perfect squares.
	for(int i = 0; i < primes.size(); i++) {
		for(int j = 0; j < 300; j++) {
			int sum = (primes[i] + (2 * (j * j)));
			composites[sum] = true;
		}
	}
	// Find the first odd number that is okay.
	for(int i = 3; i < composites.size(); i += 2) {
		if(!composites[i]) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}