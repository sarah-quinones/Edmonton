#include <iostream>

using namespace std;

// Generate the n'th term in the Fibonacci sequence.
constexpr int fib(int n) {
    if(n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char* argv[]) {
    int even_sum = 0;
    int index = 0;

    // Will loop till we hit our specific break condition.
    while(true) {
        int fibn = fib(index++); // Increment index here to save a line.

        // If our number is greater than 4 million we stop here.
        if(fibn >= 4'000'000) break;
        
        // Add only the even numbers to sum.
        even_sum = (fibn % 2 == 0) ? even_sum + fibn : even_sum;
    }
    cout << even_sum << endl;
    return 0;
}