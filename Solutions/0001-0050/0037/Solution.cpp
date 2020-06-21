#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

constexpr bool isTrunctable(int n, vector<int> &primes) {
	for(int i = 10; i < n; i *= 10) {
		if(!primes[n % i]) {
			return false;
		}
	}
	for(; n; n /= 10) {
		if(!primes[n]) {
			return false;
		}
	}
	return true;
}

int main() {
	vector<int> primes = Edmonton::generatePrimes(1'000'000, false);
	int sum = 0;
	for(int n = 11; n < primes.size(); n += 2) {
		if(isTrunctable(n, primes)) {
			sum += n;
		}
	}
	std::cout << sum << "\n";
}