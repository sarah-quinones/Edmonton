#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>

using namespace std;
using boost::multiprecision::cpp_int;

/*
Using the partition generating function..
p(n) = p(n – 1)  + p(k – 2) – p(k – 5) – p(k – 7) + p(k – 12) + p(k – 15) – p(k – 22)…
Where p(0) = 1 and p(n) = 0 for n < 0..
and k = m / 2 + 1 (k % 2 == 0) || -m / 2 + 1.
*/
int main(int argc, char *argv[]) {
	// We will need the generalized pentagonal numbers first.
	vector<cpp_int> k;
	k.push_back(1);
	int n = 1;
	// Loop through everything until we get something that fits our requirement.
	while(true) {
		int i = 0;
		int penta = 1;
		k.push_back(0);
		while(penta <= n) {
			int sign = (i % 4 > 1) ? -1 : 1;
			k[n] += sign * k[n - penta];
			k[n] %= 1'000'000;
			i++;
			// Generate the next pentagonal (generalized number).
			int j = (i % 2 == 0) ? i / 2 + 1 : -(i / 2 + 1);
			penta = j * (3 * j - 1) / 2;
		}
		if(!k[n]) {
			break;
		}
		n++;
	}
	cout << n << endl;
	return 0;
}