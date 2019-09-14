#include <iostream>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

// Generate the n'th term in the Fibonacci sequence.
cpp_int fib(cpp_int n){
    static map<cpp_int, cpp_int> memory;
    if(n <= 1){
        return n;
    }
    if(memory.count(n) > 0) {
        return memory[n];
    }
    cpp_int ret = fib(n - 1) + fib(n - 2);
    memory[n] = ret;
    return ret;
}

int main(int argc, char* argv[]) {
    int index = 1;
    while(index < 1000) {
        cout << fib(index++) << endl;
    }
    cout << index << endl;
    return 0;
}