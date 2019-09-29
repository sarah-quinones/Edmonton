#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
Since this problem is the same as #18, there's no point bruteforcing this when I can't bruteforce that one. We just need to realize that instead of going up -> down, we can go opposite way.
I.e. Read everything into the vectors as usual, and then add the larger of the two numbers to the number above it for each element in the vector. That way the one number in the first vector
will be equal to the maximum path sum that we need to take.
*/
int main(int argc, char *argv[]) {
	// Get input.
	vector<vector<int>> lines;
	ifstream input("Data.txt");
	string curr_line;
	while(getline(input, curr_line)) {
		int n;
		stringstream ss(curr_line);
		vector<int> curr_line_vec;
		while(ss >> n) {
			curr_line_vec.push_back(n);
		}
		lines.push_back(curr_line_vec);
	}
	// Jump through the vectors and sum them bottom up.
	for(int i = lines.size() - 2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			lines[i][j] += max(lines[i + 1][j], lines[i + 1][j + 1]);
		}
	}
	cout << lines[0][0] << endl;
	input.close();
	return 0;
}