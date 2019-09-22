#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

// Function that calculates the pow of two numbers, with a given modulus.
cpp_int mPow(cpp_int base, long long exponent, long long modulus) {
	cpp_int result = 1;
	while(exponent > 0) {
		if(exponent % 2 == 1) {
			result = (result * base) % modulus;
		}
		exponent >>= 1;
		base = (base * base) % modulus;
	}
	return result;
}

// We can try to just use the large number library to handle this trivially.
int main(int argc, char *argv[]) {
	cout << (28433 * mPow(2, 7830457, 10'000'000'000) + 1) % 10'000'000'000 << endl;
	return 0;
}