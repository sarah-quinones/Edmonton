#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// Function that returns the letter score of a given word.
int letterScore(string_view s) {
	int sum = 0;
	for (unsigned int i = 0; i < s.length(); i++) {
		sum += s[i] - 'A' + 1;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	// Read in the data file into the vector.
	ifstream input("Data.txt");
	vector<string> names;
	istream_iterator<string> end, start(input);
	copy(start, end, back_inserter(names));
	sort(names.begin(), names.end());

	// Go through the whole vector and sum up the scores.
	int list_sum = 0;
	for (unsigned int i = 0; i < names.size(); i++) {
		list_sum += ((i + 1) * letterScore(names[i]));
	}

	cout << list_sum << endl;
	return 0;
}