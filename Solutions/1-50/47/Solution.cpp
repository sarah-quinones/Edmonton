#include "../../Headers/Edmonton.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
For this problem we need to make sure that the distinct number of factors that a given function has is exactly 4.
So in order to optimize this for time/speed we can generate the primes and go through the number, counting the number of prime factors.
Before we return it we can add it to cache. When we search that number again later on, we have the cached results ready for us. 
*/
int main(int argc, char *argv[]) {
	// Generate the list for the first 1 million primes so we can use it to count prime factors.
	vector<bool> primes = Edmonton::
		return 0;
}