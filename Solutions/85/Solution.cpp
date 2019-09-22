#include <cmath>
#include <iostream>

using namespace std;

/*
In this problem we are given the number of rectangles that can be created using a 3 x 2 grid.
If we draw this all out on paper using for example a 5 x 4 grid we can get a simple pattern.

Rectangles are essentially a bunch of parallel lines. If there are M and N lines, we have L + 1 and W + 1 rectangles.
We need to essentially get the total combination of each type of line and multiply it out.

So it essentially becomes: (l * N * (l + 1) * (w + 1)) / 4.
*/
constexpr int countRectangles(int l, int w) {
	return ((l * w * (l + 1) * (w + 1)) / 4);
}

int main(int argc, char *argv[]) {
	// We need to find the area of the grid that will contain the closest amount to 2,000,000 rectangles.
	// Hence we use the abs function and check the lowest difference. The l and w can be brute-forced.
	int diff = INT_MAX;
	int best_l, best_w;
	for(int l = 1; l <= 2000; l++) {
		for(int w = 2000; w >= 1; w--) {
			int t_diff = abs(countRectangles(l, w) - 2000000);
			if(diff > t_diff) {
				diff = t_diff;
				best_w = w;
				best_l = l;
			}
		}
	}
	// Return area of this grid as requested.
	cout << best_l * best_w << endl;
	return 0;
}