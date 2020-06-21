#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
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
	set<long> products;
	for(long n = 1; n < 100; n++) {
		for(long m = 1; m < ((10000 / n) + 1); m++) {
			long p = n * m;
			long res = concat(n, m);
			res = concat(res, p);
			if(isPandigital(res)) {
				products.insert(p);
			}
		}
	}
	cout << accumulate(products.begin(), products.end(), 0) << endl;
	return 0;
}