#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using boost::lexical_cast;
using boost::multiprecision::cpp_int;

/*
Just a normal bruteforce, we'll generate the first couple dozen thousand cubes, sort them as strings (to match permutations) into a vector, then run a count on them.
*/

int main(int argc, char *argv[]) {
	vector<string> permutations;
	// Generate all cubes.
	for(int i = 0; i < 10'000; i++) {
		cpp_int cube = boost::multiprecision::pow((cpp_int)i, 3);
		string t = lexical_cast<string>(cube);
		sort(t.begin(), t.end());
		permutations.push_back(t);
	}
	// Go through it and count occurances of each string, break when we find what we need.
	for(int i = 0; i < permutations.size(); i++) {
		int existingPermutations = count(permutations.begin(), permutations.end(), permutations[i]);
		if(existingPermutations == 5) {
			cpp_int cube = boost::multiprecision::pow((cpp_int)i, 3);
			cout << cube << endl;
			break;
		}
	}
	return 0;
}