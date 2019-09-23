#include <iostream>
#include <vector>

using namespace std;

// Generates the proper word for each number we pass it.
string numberToWord(int n, vector<const char *> &ones, vector<const char *> &tens, vector<const char *> &hundreds) {
	string word = "";
	if(n == 1000) {
		return "onethousand";
	}
	// If it's one of the first 20 numbers.
	if(n < 20) {
		return ones[n];
	}
	// If number is less than 100, but more than 19.
	if(n < 100) {
		return tens[n / 10] + numberToWord(n % 10, ones, tens, hundreds);
	}
	// If greater than a 100.
	word = numberToWord(n % 100, ones, tens, hundreds);
	if(word.length() > 0) {
		word = "and" + word;
	}
	return hundreds[n / 100] + word;
};

int main(int argc, char *argv[]) {
	// Create string vectors for each word/prefix count and we can just get the sizes of the words in them.
	vector<const char *> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	vector<const char *> tens = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	vector<const char *> hundreds = {"", "onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};
	int sum = 0;
	for(int i = 1; i <= 1000; i++) {
		sum += numberToWord(i, ones, tens, hundreds).size();
	}
	cout << sum << endl;
	return 0;
}