#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

/*
This is a simple application of Euler's totient function.
*/

// Euler's totient function, requires a vector of primes to work for insane speed increases.
template<typename T>
T phi(T n, vector<T> &primes) {
	T res = n;
	for(T i = 0; primes[i] * primes[i] <= n; i++) {
		if(!(n % primes[i])) {
			res -= (res / primes[i]);
			while(!(n % primes[i])) {
				n /= primes[i];
			}
		}
	}
	if(n > 1) {
		res -= (res / n);
	}
	return res;
}

int main(int argc, char *argv[]) {
	vector<unsigned long long> primes = Edmonton::generatePrimes<unsigned long long>(10000);
	unsigned long long sum = 0;
	for(unsigned long long i = 1; i <= 1'000'000; i++) {
		sum += phi<unsigned long long>(i, primes);
	}
	cout << sum - 1 << endl;
	return 0;
}