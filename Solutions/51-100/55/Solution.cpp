#include "../../Headers/Edmonton.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

/*
Since we need to find the numbers and know that they will produce a palindrome within 50 iterations,
we can get away with a few numbers functions. One that will add numbers with their reversed digits,
one that will check for palindromes and one that will process a number and keep track of iterations.
The palindrome function is already made, so we just need to make the other ones.
*/

cpp_int reverseNumber(cpp_int n) {
	cpp_int re, rv = 0;
	while(n > 0) {
		re = n % 10;
		rv = (rv * 10) + re;
		n /= 10;
	}
	return rv;
}

// Check if the given number is a Lychrel number.
bool isLychrel(cpp_int n) {
	int iterations = 0;
	do {
		n += reverseNumber(n);
		iterations++;
	} while(!Edmonton::isPalindrome<cpp_int>(n, 10) && iterations < 50);
	return (iterations < 50) ? false : true;
}

int main(int argc, char *argv[]) {
	int lychrels = 0;
	for(int i = 1; i <= 10000; i++) {
		if(isLychrel(i)) {
			lychrels++;
		}
	}
	cout << lychrels << endl;
	return 0;
}