#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
We can solve this problem using a slightly upgraded version of the sum of digits function I have before that accounts for factorials.
*/

// Returns sum of the digits after they have factorials, which are hard-coded in.
template<typename T>
T sumOfDigits(T n) {
	static vector<T> factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	T sum = 0;
	while(n != 0) {
		auto d = n % 10;
		sum += factorials[d];
		n /= 10;
	}
	return sum;
}

// Returns length of chain of a given starting number. Uses a set to hold numbers already seen.
template<typename T>
T chainLength(T n) {
	// Chain length.
	int length = 0;
	set<int> checked;
	// Go through the number until we get what we need.
	int num = n;
	while(checked.find(num) == checked.end()) {
		checked.emplace(num);
		num = sumOfDigits(num);
		length++;
	}
	return length;
}

int main(int argc, char *argv[]) {
	int res = 0;
	for(int i = 1; i < 1'000'000; i++) {
		if(chainLength<int>(i) == 60) {
			res++;
		}
	}
	cout << res << endl;
	return 0;
}