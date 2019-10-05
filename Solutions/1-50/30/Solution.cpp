#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
The upperbound on the numbers we need to check will be given by 6 * 9^5, since we need need to get a 6 digit number.
The lowerbound will be two since we would like to exclude 1 from the results. If we cache the powers of the digits,
There will be a minor speed increase in advance and we can just look them up.
*/

int main(int argc, char *argv[]) {
	// Set up our lookup cache.
	vector<int> cache(10);
	for(int i = 0; i < 10; i++) {
		cache[i] = pow(i, 5);
	}
	// Simple lambda that will calculate the sum of the fifth powers of the digit.
	auto sumDigitsFifthPower = [&](int n) {
		int sum = 0;
		while(n > 0) {
			sum += cache[n % 10];
			n /= 10;
		}
		return sum;
	};
	// Loop through all the numbers and add to sum if the sum of the digits fifth powers equal to the value of the number.
	int sum = 0;
	for(int i = 2; i <= 355'000; i++) {
		if(i == sumDigitsFifthPower(i)) {
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}