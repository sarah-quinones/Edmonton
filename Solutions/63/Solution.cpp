#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
using boost::multiprecision::cpp_int;

/*
We need to find the n-digit integers that are also an n'th power. i.e. a 3 digit number that is also a third power.
So the integers we need to find are.. 10 ^ (n - 1) <= x ^ n < 10 ^ n;

Or in other words if the function L gets length of an integer then we need:
L(x ^ n) = n.

If our base is x then the maximum it can be is 9 and lowest it can be is 1.
Then we just need to get maximum value of n, which will be given by taking the log and solving for n >.
For x = 9, largest possible n = 22, so we have our upperlimits.
*/
int digitCount(cpp_int n) {
	int digits = 0;
	while(n) {
		n /= 10;
		digits++;
	}
	return digits;
}

int main(int argc, char *argv[]) {
	int result = 0;
	for(int x = 1; x < 10; x++) {
		for(int n = 1; n < 22; n++) {
			if(digitCount(boost::multiprecision::pow((cpp_int)x, n)) == n) {
				result++;
			}
		}
	}
	cout << result << endl;
	return 0;
}