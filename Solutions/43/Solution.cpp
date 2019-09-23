#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
using boost::multiprecision::cpp_int;

int main(int argc, char *argv[]) {
	vector<cpp_int> nums;
	string base = "0123456789";
	do {
		// Convert to integers.
		int a = stoull(base.substr(1, 3));
		int b = stoull(base.substr(2, 3));
		int c = stoull(base.substr(3, 3));
		int d = stoull(base.substr(4, 3));
		int e = stoull(base.substr(5, 3));
		int f = stoull(base.substr(6, 3));
		int g = stoull(base.substr(7, 3));
		if((a % 2 == 0) && (b % 3 == 0) && (c % 5 == 0) && (d % 7 == 0) && (e % 11 == 0) && (f % 13 == 0) && (g % 17 == 0)) {
			nums.push_back((cpp_int)stoull(base));
		}
	} while(next_permutation(base.begin(), base.end()));
	cpp_int sum = 0;
	for(const auto &n : nums) {
		sum += n;
	}
	cout << sum << endl;
	return 0;
}