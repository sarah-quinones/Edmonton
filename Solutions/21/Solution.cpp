#include <cmath>
#include <iostream>
#include <numeric>
#include <set>

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
	// When you use a set we don't have to worry about any duplicates.
	set<int> amicable_numbers;
	// Loop through the first 10k numbers.
	for(int i = 0; i < 10'000; i++) {
		int a = divisorSum(i);
		int b = divisorSum(a);
		// If everything matches up, we add them both to set.
		if(i == b && i != a) {
			amicable_numbers.insert(i);
			amicable_numbers.insert(b);
		}
	}
	// Print the final sum.
	cout << accumulate(amicable_numbers.begin(), amicable_numbers.end(), 0) << endl;
	return 0;
}