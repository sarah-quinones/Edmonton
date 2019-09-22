#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	// Start at 20 and only check the numbers we need to. Increment by 20 because it will be divisible by 20.
	int i = 20;
	while(i % 11 != 0 || i % 12 != 0 || i % 13 != 0 || i % 14 != 0 ||
		  i % 15 != 0 || i % 16 != 0 || i % 17 != 0 || i % 18 != 0 ||
		  i % 19 != 0) {
		i += 20;
	}
	cout << i << endl;
	return 0;
}