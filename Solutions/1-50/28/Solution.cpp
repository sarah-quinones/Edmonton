#include <iostream>

using namespace std;

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