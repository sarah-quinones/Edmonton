#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <vector>

using namespace std;

/*
Similar to 77, just a vector of primes and we iterate over N till it hits over 5000.
*/
int changeCount(int goal, vector<int> &nums) {
	vector<int> subnums(goal + 1, 0);
	subnums[0] = 1; // 1 way to make 0.
	for(const auto &coin : nums) {
		for(int i = coin; i <= goal; i++) {
			subnums[i] += subnums[i - coin];
		}
	}
	return subnums[goal];
}

int main(int argc, char *argv[]) {
	vector<int> primes = Edmonton::generatePrimes<int>(1000);
	int n = 0;
	do {
		n++;
	} while(changeCount(n, primes) < 5000);
	cout << n << endl;
	return 0;
}