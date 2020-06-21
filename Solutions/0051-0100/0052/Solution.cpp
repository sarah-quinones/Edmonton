#include "../../Headers/Edmonton.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	// This problem is fairly easy. We can get each multiple, convert it to a string and then compare all the strings.
	// The bounds for this are given because we will have 6 digits and need each one to be unique.
	for(int i = 100'000; i <= 166'000; i++) {
		vector<string> nums;
		nums.push_back(to_string(i));
		nums.push_back(to_string(i * 2));
		nums.push_back(to_string(i * 3));
		nums.push_back(to_string(i * 4));
		nums.push_back(to_string(i * 5));
		nums.push_back(to_string(i * 6));
		for(auto &n : nums) {
			sort(n.begin(), n.end());
		}
		if(Edmonton::allEqual(nums.begin(), nums.end())) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}