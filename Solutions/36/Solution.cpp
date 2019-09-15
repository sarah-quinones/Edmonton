#include <iostream>

using namespace std;

/*
Simple change of the palindrome function from problem 4 to work for arbitrary bases.
*/

int main(int argc, char* argv[]) {
    // Function to check if a given number is a palindrome in a given base.
    constexpr auto is_palindrome = [](int n, int b) {
        int r = 0, t = n;
        // Reverse the number.
        while(n > 0) {
            r = (r * b) + n % b;
            n = n / b | 0;
        }
        return (r == t) ? true : false;
    };

    // Loop through all products and check maximum palindrome.
    int sum = 0;
    for(int i = 1; i < 1'000'000; i++) {
        if(is_palindrome(i, 10) && is_palindrome(i, 2)) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}