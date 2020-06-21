#include <algorithm>
#include <iostream>

using namespace std;

/*
For this problem we need to check if a given number is a palindrome. The
conventional way to do this is simply use a while loop and reverse the digits of
the integer. Since we need to obtain the largest palindrome from the product of
two three-digit numbers, we can go backwards and check the palindromes. i.e
1000->1. After we find the first one we only need to check palindromes for the
ones after if and only if the product is larger.
*/

int main(int argc, char *argv[]) {
	// Function to check if a given number is a palindrome.
	constexpr auto is_palindrome = [](int n) {
		int r = 0, t = n;
		// Reverse the number.
		while(n != 0) {
			int remainder = n % 10;
			r = (r * 10) + remainder;
			n /= 10;
		}
		return (r == t) ? true : false;
	};
	// Loop through all products and check maximum palindrome.
	int max_palindrome = 0;
	for(int i = 1000; i > 100; i--) {
		for(int j = 1000; j > 100; j--) {
			if(i * j > max_palindrome) {
				if(is_palindrome(i * j)) {
					max_palindrome = max(max_palindrome, i * j);
				}
			}
		}
	}
	// Print the result out.
	cout << max_palindrome << endl;
	return 0;
}