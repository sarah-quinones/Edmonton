#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
For this problem we can make a few observations:
1. Since we want the largest possible number, outer ring must have 6 -> 10 as numbers, and 1->5 is inside.
2. 10 has to be on outside else we have a 17 digit string.
3. Since each number in the inner ring counts twice.. we have (1 + 2 + 3 + 4 + 5) * 2 + 6 + 7 + + 9 + 10 = 70/5 = 14 is number for each solution.
After defining all this we can just use a vector and get next permutation each time, seeing if we fit requirements or not.
*/

// Checks the result and looks for:
// 1. If node 0 is smallest.
// 2. If it's a 16 digit string.
// 3. If sum is same on all lines.
bool check(const vector<int> &vec) {
	if(vec[1] == 10 || vec[2] == 10 || vec[4] == 10 || vec[6] == 10 || vec[8] == 10) {
		return false;
	}
	if(vec[0] > vec[3] || vec[0] > vec[5] || vec[0] > vec[7] || vec[0] > vec[9]) {
		return false;
	}
	if(vec[0] + vec[1] + vec[2] != vec[3] + vec[2] + vec[4]) {
		return false;
	}
	if(vec[0] + vec[1] + vec[2] != vec[5] + vec[4] + vec[6]) {
		return false;
	}
	if(vec[0] + vec[1] + vec[2] != vec[7] + vec[6] + vec[8]) {
		return false;
	}
	if(vec[0] + vec[1] + vec[2] != vec[9] + vec[8] + vec[1]) {
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	vector<int> polygon = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	while(!check(polygon)) {
		prev_permutation(polygon.begin(), polygon.end());
	}
	string candidate = "" + to_string(polygon[0]) + to_string(polygon[1]) + to_string(polygon[2]) + to_string(polygon[3]) + to_string(polygon[2]) + to_string(polygon[4]) + to_string(polygon[5]) + to_string(polygon[4]) + to_string(polygon[6]) + to_string(polygon[7]) + to_string(polygon[6]) + to_string(polygon[8]) + to_string(polygon[9]) + to_string(polygon[8]) + to_string(polygon[1]);
	cout << candidate << endl;
	return 0;
}