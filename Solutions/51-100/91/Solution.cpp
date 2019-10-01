#include "../../Headers/Edmonton.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

/*
For this problem we can make a simple few observations:
1. The right angle is at one of the corners. 
2. P and Q can be interchanged. 
Thus we have a simple regular case and can then do the special cases easily.

So using these facts we can simply know that once we define P, we can know what Q is by getting:
Solutions for point P = min(xm-x1/dx, y1/dy).

We can mirror this on y = x and get solutions going other way.

For special case we can assume O is the right angle and then P and Q are on the axis.
*/
int main(int argc, char *argv[]) {
	// Iterate through everything by going through all possibilities of P and adding special cases.
	int result = 7500; // Starting from here for results, minimum amount of special cases.
	for(auto x = 1; x <= 50; x++) {
		for(auto y = 1; y <= 50; y++) {
			auto f = Edmonton::gcd(x, y);
			result += min(y * f / x, (50 - x) * f / y) * 2;
		}
	}
	cout << result << endl;
	return 0;
}