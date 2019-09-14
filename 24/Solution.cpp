#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Can just use simple built in function to do this for us. 
int main(int argc, char* argv[]) {
    string digits = "0123456789";
    // We already have permutation #1.
    for(int i = 1; i < 1'000'000; i++) {
        next_permutation(digits.begin(), digits.end());
    }
    cout << digits << endl;
    return 0;
}