#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// Function that returns the letter score of a given word.
int letterScore(string_view s) {
	int sum = 0;
	for(unsigned int i = 0; i < s.length(); i++) {
		sum += s[i] - 'A' + 1;
	}
	return sum;
}

// Check if a given number is triangular.
bool isTriangular(int n) {
	int s = sqrt(2 * n);
	int c = s * (s + 1) / 2;
	return (c == n);
}

int main(int argc, char *argv[]) {
	// Read in the data file into the vector.
	ifstream input("Data.txt");
	vector<string> words;
	istream_iterator<string> end, start(input);
	copy(start, end, back_inserter(words));
	// Go through the whole vector and check if score is triangular.
	int tri_count = 0;
	for(unsigned int i = 0; i < words.size(); i++) {
		if(isTriangular(letterScore(words[i]))) {
			tri_count++;
		}
	}
	cout << tri_count << endl;
	return 0;
}