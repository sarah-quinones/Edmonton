#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Problem is straight-forward enough. We read in all the strings into one vector, convert them into integers and calculate difference.
Next calculate difference in total sum of both vectors. 
*/

// Convert Roman Numerals to integer.
int romanToInt(string s) {
	unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
	int total = 0;
	for(int i = 0; i < s.length(); i++) {
		if(m[s[i + 1]] <= m[s[i]]) {
			total += m[s[i]];
		} else {
			total -= m[s[i]];
		}
	}
	return total;
}

// Function convert integers to Roman Numerals.
string intToRoman(int number) {
	int rules[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	const char *action[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	string result;
	for(unsigned int i = 0; i < 13; i++)
		while(number >= rules[i]) {
			number -= rules[i];
			result += action[i];
		}
	return result;
}

int main(int argc, char *argv[]) {
	// Read in the data file into the vector.
	ifstream input("Data.txt");
	vector<string> numerals;
	istream_iterator<string> end, start(input);
	copy(start, end, back_inserter(numerals));
	int sum = 0;
	// Process everything and put it into a different vector.
	for(const auto &n : numerals) {
		sum += n.length() - (intToRoman(romanToInt(n))).length();
	}
	cout << sum << endl;
	return 0;
}