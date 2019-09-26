#include "../../Headers/Edmonton.hpp"
#include <iostream>

using namespace std;

/*
Same as problem 28.. just rotated.

Bottom right = 9, 25, 49.. which is essentially 4n^2 + 4n  + 1. We never need to check this diagonal. No perfect square is a prime.
Top left = 5, 17, 37.. which is essentially 4n^2 + 1.
Bottom left = 7, 21, 43.. which is essentially 4n^2 + 2n + 1.
Top right = 3, 13, 31.. which is essentially 4n^2 - 2n + 1.

Thus given an n, we can get the value at each diagonal for each N, and check if it is prime or not. Then keep a running check if it is less than 10% ratio.
*/

int main(int argc, char *argv[]) {
	// Generate the primes so we can check against it to see if a number is prime.
	vector<int> primes = Edmonton::generatePrimes<int>(100'000, false);
	// Lambda expressions to calculate the n'th term in diagonal. Changed this to be a bit faster by not using pow().
	constexpr auto tl = [](int n) { return ((4 * (n * n)) + (2 * n) + 1); };
	constexpr auto bl = [](int n) { return ((4 * (n * n)) - (2 * n) + 1); };
	constexpr auto tr = [](int n) { return ((4 * (n * n)) + 1); };
	// Current n, will keep going till we hit break condition.
	int n = 1;
	int total_diagonal_nums = 0;
	int total_primes = 0;
	do {
		total_diagonal_nums += 4;
		if(Edmonton::isPrime<int>(tl(n))) {
			total_primes++;
		}
		if(Edmonton::isPrime<int>(bl(n))) {
			total_primes++;
		}
		if(Edmonton::isPrime<int>(tr(n))) {
			total_primes++;
		}
		n++;
	} while((total_diagonal_nums / 10) < total_primes);
	cout << ((2 * n) - 1) << endl;
	return 0;
}