#include <iostream>

using namespace std;

// Check for a^2 + b^2 = c^2.
constexpr bool is_pythagorean(int a, int b, int c) {
    if(((c * c) - (b * b)) == (a * a)) {
        return true;
    }
    return false;
}

constexpr bool sums_to_thousand(int a, int b, int c) {
    if((a + b + c) == 1000) {
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    // We can brute force the rest using a simple check. 
    for(int a = 1; a <= 1000; a++) {
        for(int b = a; b <= 1000; b++) {
            for(int c = a; c <= 1000; c++) {
                if(sums_to_thousand(a, b, c) && is_pythagorean(a, b, c)) {
                    cout << (a * b * c) << endl;
                }
            }
        }
    }
    return 0;
}