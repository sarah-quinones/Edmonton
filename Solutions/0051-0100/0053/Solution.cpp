#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <unordered_map>

using namespace std;
using boost::multiprecision::cpp_int;

// Generate the n'th term for the factorial sequence. Uses a cache to speed up results.
cpp_int factorial(int n) {
	static unordered_map<int, cpp_int> cache;
	if(auto it = cache.find(n); it != cache.end()) {
		return (*it).second;
	}
	if(n > 1) {
		cpp_int res = n * factorial(n - 1);
		cache.insert({n, res});
		return res;
	} else {
		return 1;
	}
}

// Gets the combination.
cpp_int nCr(int n, int r) {
	return (factorial(n) / (factorial(r) * factorial(n - r)));
}

int main(int argc, char *argv[]) {
	int over_million_count = 0;
	for(int n = 1; n < 101; n++) {
		for(int r = 1; r <= n; r++) {
			if(nCr(n, r) > 1'000'000) {
				over_million_count++;
			}
		}
	}
	cout << over_million_count << endl;
	return 0;
}