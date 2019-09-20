#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/* 
For this problem there is a 20 x 20 grid. We need the diagonals and the horizontal/vertical products.
Assuming we start from point (0, 0). The maximum we need to iterate is till point (17, 17)
Everything beyond that will fall out of range if we try and extend our 4 numbers past that point.
*/

int main(int argc, char *argv[]) {
	// Easier to just copy paste grid here instead of putting it in a file.
	vector<vector<int>> grid = {
		{8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
		{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
		{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
		{52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
		{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
		{24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
		{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
		{67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
		{24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
		{21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
		{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
		{16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
		{86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
		{19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
		{4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
		{88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
		{4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
		{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
		{20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
		{1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}};

	// Lambda to obtain the value of the number at location (y, x).
	// We inverse it due to the way 2D vectors work.
	auto getValue = [&](unsigned int y, unsigned int x) {
		if(0 <= y && 0 <= x && y < grid.size() && x < grid[y].size()) {
			return grid[y][x];
		}
		return 0; // Return a zero so the product is invalid.
	};

	// Loop through the grid.
	unsigned int max_product = 0;
	for(unsigned int y = 0; y < 17; y++) {
		for(unsigned int x = 0; x < 17; x++) {
			// Horizontal, Vertical, Diagonal 1, Diagonal 2 products with current grid square as first number.
			unsigned int h_p = 1, v_p = 1, d_1 = 1, d_2 = 1;
			for(unsigned int i = 0; i < 4; i++) {
				h_p *= getValue(y, x + i);
				v_p *= getValue(y + i, x);
				d_1 *= getValue(y + i, x + i);
				d_2 *= getValue(y + i, x - i);
			}
			// Apparantly you can only pass two items to std::max().
			max_product = max<int, int>(max<int, int>(max<int, int>(max<int, int>(h_p, v_p), d_1), d_2), max_product);
		}
	}
	cout << max_product << endl;
}