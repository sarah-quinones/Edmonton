#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <set>

using namespace std;
using boost::multiprecision::cpp_int;

int main(int argc, char *argv[]) {
	// Sets only hold unique integers, making it the perfect container.
	set<cpp_int> numbers;
	for(cpp_int a = 2; a < 101; a++) {
		for(int b = 2; b < 101; b++) {
			numbers.emplace(boost::multiprecision::pow(a, b));
		}
	}
	cout << numbers.size() << endl;
	return 0;
}