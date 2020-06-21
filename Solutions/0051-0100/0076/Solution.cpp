#include <iostream>
#include <vector>

using namespace std;

/*
Literally identical problem to 31. Just changed the function variable names.
*/

int changeCount(int goal, vector<int> &nums) {
	vector<int> subnums(goal + 1, 0);
	subnums[0] = 1; // 1 way to make 0.
	for(const auto &coin : nums) {
		for(int i = coin; i <= goal; i++) {
			subnums[i] += subnums[i - coin];
		}
	}
	return subnums[goal];
}

int main(int argc, char *argv[]) {
	vector<int> nums;
	for(int i = 1; i < 100; i++) {
		nums.push_back(i);
	}
	cout << changeCount(100, nums) << endl;
	return 0;
}