#include <iostream>

using namespace std;

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