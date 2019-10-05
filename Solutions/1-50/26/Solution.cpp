#include "../../Headers/Debug.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
For this question we can make an interesting observation(s):
1. Each of the recurring cycles ends once a digit it has encountered before shows up again. 
2. The number must be odd (and prime) but we won't bother generating primes for this question.
*/

int main(int argc, char *argv[]) {
	int cycle_length = 0;
	int max_i = 0;
	for(int i = 1001; i > 1; i -= 2) {
		if(cycle_length >= i) {
			break;
		}
		vector<int> remainders(i);
		int value = 1, pos = 0;
		while(remainders[value] == 0 && value != 0) {
			remainders[value] = pos;
			value *= 10;
			value %= i;
			pos++;
		}
		if(pos - remainders[value] > cycle_length) {
			cycle_length = pos - remainders[value];
			max_i = i;
		}
	}
	cout << max_i << endl;
	return 0;
}