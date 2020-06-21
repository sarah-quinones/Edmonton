#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
This problem is handled almost identically to problem 18/67. Except instead of a pyramid we have a simple matrix that we can deal with and use instead.
We will sum up stuff going top left, and then go in reverse order and pick the min sum of each, and our final minimum sum should be stored in matrix[0][0].
*/

int main(int argc, char *argv[]) {
	// Get input.
	vector<vector<int>> matrix;
	ifstream input("Data.txt");
	string curr_row;
	while(getline(input, curr_row)) {
		stringstream ss(curr_row);
		vector<int> curr_row_vec;
		for(int n; ss >> n;) {
			curr_row_vec.push_back(n);
			if(ss.peek() == ',') {
				ss.ignore();
			}
		}
		matrix.push_back(curr_row_vec);
	}
	// Loop through the matrix and start finding the mininum path going up and to the left, starting at 79, 79.
	// The first set of loops puts the sums of each number in the location of the matrix.
	// We start from the 78, 78 mark cause the bottom row/right most column don't need any summation.
	for(int i = matrix.size() - 2; i >= 0; i--) {
		matrix[matrix.size() - 1][i] += matrix[matrix.size() - 1][i + 1];
		matrix[i][matrix.size() - 1] += matrix[i + 1][matrix.size() - 1];
	}
	// Loop through matrix and get mininum path.
	for(int i = matrix.size() - 2; i >= 0; i--) {
		for(int j = matrix.size() - 2; j >= 0; j--) {
			matrix[i][j] += min(matrix[i + 1][j], matrix[i][j + 1]);
		}
	}
	cout << matrix[0][0] << endl;
	input.close();
	return 0;
}