#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
We can model this as a statistics problem by getting the average position of each character, and then sorting them.
*/

// Kinda hackish, but it works.
void process(int num, vector<pair<double, double>> &chars) {
	// For each digit in num, process it and then put it in correction position.
	int d1 = num % 10;
	chars[d1].first += 2;
	chars[d1].second++;
	num /= 10;
	int d2 = num % 10;
	chars[d2].first += 1;
	chars[d2].second++;
	num /= 10;
	int d3 = num % 10;
	chars[d3].first += 0;
	chars[d3].second++;
}

int main(int argc, char *argv[]) {
	// Sum of Positions, Count of Appearances.
	vector<pair<double, double>> chars;
	for(int i = 0; i < 10; i++) {
		chars.push_back(make_pair(0, 0));
	}
	// Read input and process it as I go along.
	fstream input("Data.txt");
	int num;
	while(input >> num) {
		process(num, chars);
	}
	input.close();
	// Let's go through everything and calculate stuff out for us.
	vector<pair<double, int>> freqs;
	int i = 0;
	for(auto &c : chars) {
		auto t = c.first / c.second;
		if(t == t) {
			freqs.push_back(make_pair(t, i++));
		} else {
			i++;
		}
	}
	sort(freqs.begin(), freqs.end());
	for(auto &f : freqs) {
		if(f.first == f.first) {
			cout << f.second;
		}
	}
	input.close();
	return 0;
}