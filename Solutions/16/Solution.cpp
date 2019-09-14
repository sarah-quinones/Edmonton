#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

mp::cpp_int sum_of_digits(mp::cpp_int num) {
    mp::cpp_int sum = 0;
    while(num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    cout << sum_of_digits(mp::pow((mp::cpp_int)2, 1000)) << endl;
    return 0;
}