#include "../../Headers/Edmonton.hpp"
#include <iostream>

using namespace std;

/*
We can take a look at Farey Sequences which is defined as (Wikipedia:)
In mathematics, the Farey sequence of order n is the sequence of completely reduced fractions, 
either between 0 and 1, or without this restriction,
which when in lowest terms have denominators less than or equal to n, arranged in order of increasing size.
*/
int main(int argc, char *argv[]) {
	/*
    We can generate the next terms of the sequence until n and d are equal to 1 / 2.
    Since we need the first two terms to get started, we have 1/3 and we can find 4000/11999 by hand.
    */
	int res = 0, p_n = 1, p_d = 3, n_n = 4000, n_d = 11999;
	while(!(n_n == 1 && n_d == 2)) {
		int nt_n = ((12000 + p_d) / n_d) * n_n - p_n;
		int nt_d = ((12000 + p_d) / n_d) * n_d - p_d;
		p_n = n_n;
		p_d = n_d;
		n_n = nt_n;
		n_d = nt_d;
		res++;
	}
	cout << res << endl;
	return 0;
}