#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

/*
The lattice in this problem is just a very cleverly combinatorics question. So we just need to calculate the factorials. 
The factorial function is a bit updated to store previous results so it goes quicker.
Using boost's large nber library so it makes it easier for us.
*/

// Generate the n'th term for the factorial sequence.
cpp_int factorial(int n) {
	if(n > 1) {
		return n * factorial(n - 1);
	} else {
		return 1;
	}
}

cpp_int nCr(int n, int r) {
	return (factorial(n) / (factorial(r) * factorial(n - r)));
}

int main(int argc, char *argv[]) {
	cout << nCr(40, 20) << endl;
	return 0;
}