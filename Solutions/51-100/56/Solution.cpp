#include "../../Headers/Edmonton.hpp"
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

/*
Since the digit count for the numbers scale at an insane rate, we can safely assume that A and B are >= 90 and < 100. Rest can be bruteforced.
*/

int main(int argc, char *argv[]) {
	int max_digitial_sum = 0;
	for(int a = 90; a < 100; a++) {
		for(int b = 90; b < 100; b++) {
			max_digitial_sum = max(max_digitial_sum, Edmonton::sumOfDigits<int, cpp_int>(boost::multiprecision::pow((cpp_int)a, b)));
		}
	}
	cout << max_digitial_sum << endl;
}