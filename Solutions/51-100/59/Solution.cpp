#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*
For this problem I just read in the file and sum up the ASCII values.
*/

int main(int argc, char *argv[]) {
	// Obtain input.
	vector<unsigned char> encrypted;
	ifstream input("Data.txt");
	while(true) {
		unsigned int curr;
		input >> curr;
		if(!input) {
			break;
		}
		encrypted.push_back(curr);
		input.get();
	}
	// This key was gotten by hand using some freq analysis.
	const unsigned char key[] = {'g', 'o', 'd'};
	// XOR everything and sum it up ASCII wise.
	unsigned int sum = 0;
	for(int pos = 0; pos < encrypted.size(); pos++) {
		char temp = encrypted[pos] ^ key[pos % 3];
		sum += (unsigned int)temp;
	}
	cout << sum << endl;
	return 0;
}