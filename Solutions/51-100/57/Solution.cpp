#include "../../Headers/Edmonton.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

/* 
Really straightforward problem to brute-force. 
We don't really need to worry about the actual decimals, the numerator and denominator follow an obvious pattern where:
1. numerator += 2 * denominator
2. denominator = numerator - denominator
for each of the expansion/iteration we are testing.
*/
int main(int argc, char *argv[]) {
	int num_count = 0;
	cpp_int numerator = 3, denominator = 2;
	for(int i = 1; i < 1'000; i++) {
		numerator += 2 * denominator;
		denominator = numerator - denominator;
		if(Edmonton::digitCount<int, cpp_int>(numerator) > Edmonton::digitCount<int, cpp_int>(denominator)) {
			num_count++;
		}
	}
	cout << num_count << endl;
	return 0;
}