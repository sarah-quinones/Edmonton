#include "../../Headers/Edmonton.hpp"
#include <iostream>

using namespace std;

/*
If our resulting numerator and denominator are 1 <= n < d <= 9 and the number we are cancelling are 1 <= c <= 9. Then n/d < 1.
After that we know our solution space is fairly straight forward with some algebraic manipulation.
*/

int main(int argc, char *argv[]) {
	unsigned int np = 1, dp = 1;
	for(unsigned int c = 1; c <= 9; c++) {
		for(unsigned int d = 1; d < c; d++) {
			for(unsigned int n = 1; n < d; n++) {
				if(((n * 10 + c) * d) == ((c * 10 + d) * n)) {
					np *= n;
					dp *= d;
				}
			}
		}
	}
	cout << dp / Edmonton::gcd(np, dp) << endl;
	return 0;
}