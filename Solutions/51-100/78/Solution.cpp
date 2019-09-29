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
	vector<cpp_int> partitions(100000);
	partitions.push_back(1);
	int n = 1;
	while(true) {
		int index = 0, gpenta = 1;
		partitions.push_back(0);
		while(gpenta <= n) {
			int sign = (index % 4 > 1) ? -1 : 1;
			partitions[n] += sign * partitions[n - gpenta];
			partitions[n] %= 1000000;
			index++;
			int j = (!(index % 2)) ? index / 2 + 1 : (-index / 2 + 1);
			gpenta = j * (3 * j - 1) / 2;
		}
		if(!partitions[n]) {
			break;
		}
		n++;
	}
	cout << n << endl;
	return 0;
}