#include <iostream>

using namespace std;

// Calculate the n'th triangular number.
constexpr int triangular(int n) {
    return (n * (n + 1)) / 2;
}

// Calculates the number of divisors a number has using prime factorization.
constexpr int divisorCount(int n) {
    if(n == 1) {
        return 1;
    }
    int number = n, i = 2, p = 1;
    while(i * i <= n) {
        int c = 1;
        while(n % i == 0) {
            n /= i;
            c++;
        }
        i++;
        p *= c;
    }
    if(n == number || n > 1) {
        return p *= 1 + 1;
    }
    return p;
}

int main(int argc, char* argv[]) {
    // Get the first number to have over 500 divisors.
    int n = 0;
    int tri = 0;
    do {
        tri = triangular(n++);
    } while (divisorCount(tri) < 500);
    cout << tri << endl;
    return 0;
}