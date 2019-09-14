#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using boost::multiprecision::cpp_int;
using boost::lexical_cast;

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
    int num_digits = 0;
    while(num_digits != 1000) {
        string s = lexical_cast<string>(fib(index++));
        num_digits = s.size();
    }
    cout << (index - 1) << endl;
    return 0;
}