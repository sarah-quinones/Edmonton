#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

/*
This problem would take way too long to brute-force since going upto a million and checking the gcd of each is crazy.
Instead we can realize that we have a target fraction a / b. 
We want to generate a fraction for each d such that n / d is the largest fraction possible below a / b.
So basically n / d < a / b => nb = da.
So in essence for each d we generate we can get the correct n by doing ad - 1 / b.
After we generate each fraction, we want to check if the older one is better than current one (i.e. larger).
We can also use a constexpr lambda to automatically calculate all of this before hand for us.
*/

int main(int argc, char *argv[]) {
	constexpr int a = 3, b = 7;
	int b_n = 0, b_d = 1;
	for(unsigned int d = 1; d <= 1'000'000; d++) {
		int n = (a * d - 1) / b;
		if(n * b_d > b_n * d) {
			b_d = d;
			b_n = n;
		}
	}
	cout << b_n << " / " << b_d << endl;
	return 0;
}