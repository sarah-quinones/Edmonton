#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Calculates the sum of the proper divisors of a number.
constexpr int divisorSum(int num) {
	int sum = 0;
	for(int i = 2; i <= sqrt(num); i++) {
		if(num % i == 0) {
			if(i == (num / i)) {
				sum += i;
			} else {
				sum += (i + (num / i));
			}
		}
	}
	return sum + 1;
}

int main(int argc, char *argv[]) {
	// Find all the abundant numbers.
	vector<int> abundantNumbers;
	for(int i = 2; i <= 28'123; i++) {
		if(divisorSum(i) > i) {
			abundantNumbers.push_back(i);
		}
	}
	// Create a vector of size limit + 1 and use it to mark as abundant or not.
	vector<bool> allNums(28'124, false);
	// Loop through the abundantNumbers and add them up, checking off numbers as we get to them.
	for(int i = 0; i < abundantNumbers.size(); i++) {
		for(int j = i; j < abundantNumbers.size(); j++) {
			// If the sum is less than limit we'll mark it.
			int sum = abundantNumbers[i] + abundantNumbers[j];
			if(sum <= 28123) {
				allNums[sum] = true;
			} else {
				break;
			}
		}
	}
	int sum = 0;
	// Go through everything and add them up.
	for(int i = 1; i <= 28'123; i++) {
		if(!allNums[i]) {
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}