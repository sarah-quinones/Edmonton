#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost::multiprecision;

string lastN(string input, int n){
    int inputSize = input.size();
    return (n > 0 && inputSize > n) ? input.substr(inputSize - n) : "";
}

int main(int argc, char* argv[]) {
    cpp_int sum = 0;
    for(cpp_int i = 1; i < 1001; i++) {
        sum += boost::multiprecision::pow(i, (int)i);
    }
    cout << lastN(sum.str(), 10) << endl;
    return 0;
}