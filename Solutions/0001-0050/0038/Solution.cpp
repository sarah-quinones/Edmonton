#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

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