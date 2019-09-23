#include <iostream>

using namespace std;

// Obtains the sum of the digits of a number.
constexpr int squareDigitsSum(int n) {
	int sum = 0;
	while(n) {
		sum += (n % 10) * (n % 10);
		n /= 10;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	int results = 0;
	for(int i = 1; i < 10'000'000; i++) {
		int t = i;
		while(t != 89 || t != 1) {
			if(t == 89) {
				results++;
				break;
			} else if(t == 1) {
				break;
			} else {
				t = squareDigitsSum(t);
			}
		}
	}
	cout << results << endl;
	return 0;
}