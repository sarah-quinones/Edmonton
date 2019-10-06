#include "../../Headers/Edmonton.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

/*
So for this problem there is a relation between the numerator, the index and the fractions:
index   num     fraction
1       2       1
2       3       2
3       8       1
4       11      1
5       19      4
6       87      1
7       106     1
8       193     6
9       1264    1
10      1457    1
Then num = num(i - 2) + num(i - 1) x fraction(i - 1)
*/

int main(int argc, char *argv[]) {
	cpp_int den = 1, num = 2, temp;
	for(int i = 2; i <= 100; i++) {
		temp = den;
		int c = (i % 3 == 0) ? 2 * (i / 3) : 1;
		den = num;
		num = c * den + temp;
	}
	cout << Edmonton::sumOfDigits<int, cpp_int>(num) << endl;
}