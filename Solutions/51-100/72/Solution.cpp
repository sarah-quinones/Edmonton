#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

/*
This is a simple application of Euler's totient function.
*/

int main(int argc, char *argv[]) {
	vector<unsigned long long> primes = Edmonton::generatePrimes<unsigned long long>(10000);
	unsigned long long sum = 0;
	for(unsigned long long i = 1; i <= 1'000'000; i++) {
		sum += Edmonton::phi<unsigned long long>(i, primes);
	}
	cout << sum - 1 << endl;
	return 0;
}