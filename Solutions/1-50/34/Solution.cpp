#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

// Returns n!
cpp_int factorial(cpp_int n) {
	if(n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

// Returns the sum of the factorials of the digits of a number.
cpp_int sumDigitsFactorial(cpp_int n) {
	cpp_int sum = 0;
	while(n) {
		sum += factorial(n % 10);
		n /= 10;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	cpp_int sum = 0;
	// Randomly decided to put limit as 100,000 for now.
	for(cpp_int i = 3; i <= 100'000; i++) {
		sum = (i == sumDigitsFactorial(i)) ? sum + i : sum;
	}
	cout << sum << endl;
	return 0;
}