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

cpp_int sum_of_digits(cpp_int num) {
	cpp_int sum = 0;
	while(num) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	cout << sum_of_digits(factorial(100)) << endl;
	return 0;
}