#include <iostream>

using namespace std;

/*
The numbers of the diagonals must follow a simple pattern.. so given the sample starting grid we can figure out the formula for each diagonal.

Grid is:
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

Top right = 9, 25, 49.. which is essentially 4n^2 + 4n  + 1.
Bottom left = 5, 17, 37.. which is essentially 4n^2 + 1.
Top left = 7, 21, 43.. which is essentially 4n^2 + 2n + 1.
Bottom right = 3, 13, 31.. which is essentially 4n^2 - 2n + 1.

Thus given an n, we can get the value for each diagonal and sum them all up, and then add 1 at end and get the final result.
*/

int main(int argc, char *argv[]) {
	// Lambda expressions to calculate the n'th term in diagonal.
	constexpr auto tr = [](int n) { return ((4 * (n * n)) + (4 * n) + 1); };
	constexpr auto tl = [](int n) { return ((4 * (n * n)) + (2 * n) + 1); };
	constexpr auto br = [](int n) { return ((4 * (n * n)) - (2 * n) + 1); };
	constexpr auto bl = [](int n) { return ((4 * (n * n)) + 1); };
	// Running sum, we start at 1 to account for middle element. We go until n = 500, since we need to split diagonals in half.
	int sum = 1;
	for(int n = 1; n < 501; n++) {
		sum = sum + tr(n) + tl(n) + br(n) + bl(n);
	}
	cout << sum << endl;
	return 0;
}