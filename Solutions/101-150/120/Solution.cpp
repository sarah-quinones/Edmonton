#include <iostream>

using namespace std;

/*
For all values of n that are even, remainder is always 2.
For all values of n that are odd, remainder is always 2an.

Thus maximum value of remainder is by getting 2n as close to a as possible.

For odd a: r_max = (a-1)a.
For even a: r_max = (a-2)a.

r_max is then (a-1)/4 * a.
*/

int main(int argc, char* argv[]) {
    int sum_r_max = 0;
    for(int a = 3; a <= 1000; a++) {
        sum_r_max += ((a - 1) / 2 * 2 * a);
    }
    cout << sum_r_max << endl;
    return 0;
}