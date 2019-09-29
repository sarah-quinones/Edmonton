#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
So this problem is a bit more involved than the last one, so instead of optimizing and filling out the matrix for the entire solution, we need to do it in two passes, column by column instead.
So when we scan a column we do two passes as follows:
1. Go down the column, and check if the minimum is to go to the right, or to go down, and mark it as such.
2. Go up the column and see if it is cheaper to go up the column or to use the previous computation instead.
While we do this for the columns one by one, we go to the left one column and perform computation again, slowly processing each column individually.
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
	// Set up our initial vector.
	vector<int> ans(matrix.size());
	for(int i = 0; i < matrix.size(); i++) {
		ans[i] = matrix[i][matrix.size() - 1];
	}
	// Go column by column.
	for(int i = matrix.size() - 2; i >= 0; i--) {
		// Add sum to running column which will be optimized.
		ans[0] += matrix[0][i];
		// Pass 1.
		for(int j = 1; j < matrix.size(); j++) {
			ans[j] = min(ans[j - 1] + matrix[j][i], ans[j] + matrix[j][i]);
		}
		// Pass 2.
		for(int j = matrix.size() - 2; j >= 0; j--) {
			ans[j] = min(ans[j], ans[j + 1] + matrix[j][i]);
		}
	}
	// Output result.
	cout << *min_element(ans.begin(), ans.end()) << endl;
	input.close();
	return 0;
}