#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

/*
Simple observation but the more distinct prime factors you have, the larger the maximum for n/phi(n).
So we multiply by prime factors until we go over 1 million.
*/

int main(int argc, char *argv[]) {
	vector<int> primes = Edmonton::generatePrimes<int>(100);
	int n = 1, index = 0;
	while(primes[index] * n <= 1'000'000) {
		n *= primes[index++];
	}
	cout << n << endl;
}