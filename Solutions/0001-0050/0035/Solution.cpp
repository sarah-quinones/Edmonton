#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Checks if all rotations of the number are prime. Just a clever optimization of the rotateNum function I had in an earlier iteration.
bool isCircularPrime(int n, const vector<int> &primes) {
	int left = floor(log10(n)) + 1;
	int power = pow(10, left) - 1;
	for(int i = 1; i < left; i++) {
		n = (n + n % 10 * power) / 10;
		if(!primes[n]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	vector<int> primes = Edmonton::generatePrimes(1'000'000, false);
	int circ_primes = 4;
	// We start off with the first four single digit primes as circular.
	for(int i = 11; i < 1'000'000; i += 2) {
		if(isCircularPrime(i, primes) && Edmonton::isPrime<int>(i, primes)) {
			circ_primes++;
		}
	}
	cout << circ_primes << endl;
	return 0;
}