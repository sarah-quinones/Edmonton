#include <cmath>
#include <iostream>

using namespace std;

// We don't need to check for triangle numbers, because all hexagonal numbers are by definition triangular.
constexpr bool isPentagonal(unsigned long long x) {
	double n = (1 + sqrt(24 * x + 1)) / 6;
	return n == (unsigned long long)n;
}

int main(int argc, char *argv[]) {
	unsigned long long H = 0, i = 144;
	while(true) {
		// Generates the equivalant hexagonal number.
		H = i * ((2 * i) - 1);
		if(isPentagonal(H)) {
			cout << H << endl;
			break;
		}
		i++;
	}
	return 0;
}