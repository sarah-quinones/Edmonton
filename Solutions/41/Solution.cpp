#include "../../Headers/Edmonton.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	string s = "7654321";
	while(Edmonton::isPrime<int>(stoi(s)) == false) {
		prev_permutation(s.begin(), s.end());
	}
	cout << s << endl;
	return 0;
}