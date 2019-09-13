#include <iostream>

using namespace std;

constexpr int sum_of_the_squares(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += (i * i);
    }
    return sum;
}

constexpr int square_of_the_sum(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return (sum * sum);
}

int main(int argc, char* argv[]) {
    cout << square_of_the_sum(100) - sum_of_the_squares(100) << endl;
    return 0;
}