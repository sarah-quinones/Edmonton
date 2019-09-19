#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;
using boost::multiprecision::cpp_int;

int main(int argc, char *argv[]) {
	// Read in the data file into the vector.
	ifstream input("Data.txt");
	vector<cpp_int> numbers;
	istream_iterator<cpp_int> end, start(input);
	copy(start, end, back_inserter(numbers));

	// Accumulate the result and put it into a variable.
	cpp_int result = accumulate(numbers.begin(), numbers.end(), (cpp_int)0);

	// Print the first 10 digits.
	while(cpp_int(result / (cpp_int)pow(10, 10)) != 0) {
		result = result / 10;
	}
	cout << result << endl;
	return 0;
}