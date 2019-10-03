#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <string>
#include <vector> // 10000000

using namespace std;

/*
Can probably brute-force this fairly easily.
*/
template<typename T>
bool isPermutation(T a, T b) {
	string s_a = to_string(a);
	string s_b = to_string(b);
	if(is_permutation(s_a.begin(), s_a.end(), s_b.begin())) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	// Set up variables.
	double best_ratio = numeric_limits<double>::max();
	unsigned int best_n = 0;
	// Set-up for the totient function I use.
	vector<unsigned int> primes = Edmonton::generatePrimes<unsigned int>(10000);
	for(unsigned int n = 2; n < 10'000'000; n++) {
		// Check if they are permutations.
		unsigned int totient = Edmonton::phi<unsigned int>(n, primes);
		if(isPermutation<unsigned int>(n, totient)) {
			double ratio = ((double)n) / totient;
			if(ratio < best_ratio) {
				best_n = n;
				best_ratio = ratio;
			}
		}
	}
	cout << best_n << " : " << best_ratio << endl;
	return 0;
}