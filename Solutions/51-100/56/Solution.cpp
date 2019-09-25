#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

int main(int argc, char *argv[]) {
	cpp_int a = boost::multiprecision::pow(cpp_int(100), 100);
	cout << a << endl;
}