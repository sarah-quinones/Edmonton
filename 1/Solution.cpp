#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int sum = 0;
    // We can start at 3 because anything lower isn't a multiple.
    for(auto i = 3; i < 1000; i++) {
        sum = (i % 3 == 0 || i % 5 == 0) ? sum + i : sum;
    }
    cout << sum << endl;
    return 0;
}