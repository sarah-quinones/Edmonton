#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;

/*
Just abuse the fact that the exponents can be re-written as algorithms.
I am not proud of this code.
*/
int main(int argc, char *argv[]) {
	// Get input.
	vector<tuple<int, int>> values;
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
		values.push_back(make_tuple(curr_row_vec[0], curr_row_vec[1]));
	}
	vector<double> temp;
	for(const auto &np : values) {
		temp.push_back(log10(get<0>(np)) * get<1>(np));
	}
	int em_index = max_element(temp.begin(), temp.end()) - temp.begin();
	cout << em_index + 1 << endl;
	return 0;
}