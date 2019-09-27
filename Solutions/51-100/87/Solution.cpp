#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
Can just brute-force this in a fairly straight-forward based manner. Just need to take care to use larger numbers.
*/
constexpr unsigned long long genVal(unsigned long long a, unsigned long long b, unsigned long long c) {
	return (a * a) + (b * b * b) + (c * c * c * c);
}

int main(int argc, char *argv[]) {
	// Only have to go upto the roots of 50 million.
	vector<unsigned long long> primesSQ = Edmonton::generatePrimes<unsigned long long>(7081);
	vector<unsigned long long> primesCU = Edmonton::generatePrimes<unsigned long long>(368);
	vector<unsigned long long> primesQD = Edmonton::generatePrimes<unsigned long long>(84);
	vector<int> created(50'000'000, 0);
	// Mark everything off in the vector if we create it.
	for(int i = 0; i < primesSQ.size(); i++) {
		for(int j = 0; j < primesCU.size(); j++) {
			for(int k = 0; k < primesQD.size(); k++) {
				auto val = genVal(primesSQ[i], primesCU[j], primesQD[k]);
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