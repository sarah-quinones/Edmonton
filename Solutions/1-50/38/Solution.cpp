#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*
For this problem we can make a couple of initial observations:
1. The base number we are multiplying must be 4 digits, and it must start with 9, in order to maximize the concated number.
2. Since a 4 digit number starting with 9 multipled by 2 will give us 5 digits, we never have to check for any n > 2.
*/

// Check if a number is pandigital.
bool isPandigital(long n) {
	string b = "123456789";
	string r = to_string(n);
	sort(r.begin(), r.end());
	return (b == r);
}

// Concat numbers together.
long concat(long a, long b) {
	long c = b;
	while(c > 0) {
		a *= 10;
		c /= 10;
	}
	return a + b;
}

int main(int argc, char *argv[]) {
	long best = 0;
	for(long i = 9000; i <= 9999; i++) {
		long result = concat(i, 2 * i);
		if(isPandigital(result)) {
			best = max(result, best);
		}
	}
	cout << best << endl;
	return 0;
}