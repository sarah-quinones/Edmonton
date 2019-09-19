#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	// Lambda to get value of current digit.
	auto getDigit = [&](char c) { return (c - '0'); };

	string irrational = "";
	int num = 1, product = 1;
	while(irrational.size() < 1'000'000) {
		irrational += to_string(num++);
	}

	// We account for the offset in char array.
	product = product * getDigit(irrational[0]) * getDigit(irrational[9]) * getDigit(irrational[99]) * getDigit(irrational[999]) * getDigit(irrational[9999]) * getDigit(irrational[99999]) * getDigit(irrational[999999]);
	cout << product << endl;
	return 0;
}