#include <iostream>

using namespace std;

/*
This problem is essentially just optimizing a bunch of the math out, so starting from what we know:

1. a^2 + b^2 = c^2
2. a + b + c = p
3. p <= 1000
4. If a and b are even then c is even, and p must be even.
5. If a or b is odd, then c is odd, p even.
6. If a and b odd, then c even and p even.

So given that information you can calculate the maximum bounds of a and b by setting each to 0 and solving for other.
So it ends up being b <= 500 and a <= 500, with c being whatever the rest is.

Also if you plug equation 2 into equation 1 you will end up getting an equation of the form:

b = (p^2 - 2 * p * a) / (2 * (p - a))

So as long as we get an integer out of b, then by subbing in the other two parameters we can get the triplets.

Since p is always even, we can skip all odd numbers and limit our search based on that.
*/

int main(int argc, char *argv[]) {
	int highest_triplet_count = 0, max_p = 0;
	for(int p = 2; p <= 1'000; p += 2) {
		int triplet_count = 0;
		// Since we know that a <= b and a < c && b < c, we only have to search for p / 3.
		for(int a = 2; a < p / 3; a++) {
			// Check our equation and if b is an integer result.
			if(p * (p - 2 * a) % (2 * (p - a)) == 0) {
				triplet_count++;
			}
		}
		// If we reach a new max triplet count then:
		if(triplet_count > highest_triplet_count) {
			max_p = p;
			highest_triplet_count = triplet_count;
		}
	}
	cout << max_p << endl;
	return 0;
}