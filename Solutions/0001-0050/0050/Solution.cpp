#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	// This vector contains all primes upto 1 million. We use it to add primes to our sum/chain.
	vector<int> primes = Edmonton::generatePrimes<int>(1'000'000);
	// This vector contains all numbers upto 1 million and if they are primes or not. Using it to see if a number is a prime.
	vector<int> primeCheck = Edmonton::generatePrimes<int>(1'000'000, false);
	// Loop through every prime number in the first vector and sum them up until we hit limit or if we encounter a none prime.
	// If sequence is longer and the summed prime is larger than previous one, we set new ones up.
	int max_sum = 0, max_chain_length = INT_MIN;
	for(int i = 0; i < primes.size(); i++) {
		int curr_sum = 0;
		for(int j = i; j < primes.size(); j++) {
			curr_sum += primes[j];
			// Check if we cross the limit for the sum.
			if(curr_sum > 1'000'000) {
				break;
			}
			// Check if the sum isn't prime, the sum is larger than the current sum, and the chain length is larger than previous chain length.
			if(primeCheck[curr_sum] && curr_sum > max_sum && (j - i) > max_chain_length) {
				max_sum = curr_sum;
				max_chain_length = j - i;
			}
		}
	}
	cout << max_sum << endl;
	return 0;
}