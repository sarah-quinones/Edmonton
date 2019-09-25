#include "../../Headers/Edmonton.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int a_max = 0, b_max = 0, n_max = 0;
	// Loop through and brute force everything, keeping track of the chains.
	for(int a = -1000; a <= 1000; a++) {
		for(int b = -1000; b <= 1000; b++) {
			int n = 0;
			// Loop through numbers until we get something that isn't prime.
			while(Edmonton::isPrime<int>(abs(n * n + a * n + b))) {
				n++;
			}
			if(n > n_max) {
				n_max = n;
				a_max = a;
				b_max = b;
			}
		}
	}
	cout << a_max * b_max << endl;
	return 0;
}