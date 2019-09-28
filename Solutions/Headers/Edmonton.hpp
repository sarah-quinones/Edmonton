#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

/*
A collection of useful functions that I came up with when solving these problems and that are used often.
Uses templates so it can be easy to get correct number type, including but not limited to boost.
*/
namespace Edmonton {
	// Generate the n'th term in the Fibonacci sequence.
	template<typename T>
	T fib(T n) {
		if(n <= 1) {
			return n;
		}
		return fib(n - 1) + fib(n - 2);
	}

	// Check if a number is a palindrome in the relevant base.
	template<typename T>
	bool isPalindrome(T n, T b) {
		T r = 0, t = n;
		// Reverse the number.
		while(n > 0) {
			r = (r * b) + n % b;
			n = n / b | 0;
		}
		return (r == t) ? true : false;
	}

	// When checking for prime numbers we only need to go till square root of N.
	template<typename T>
	bool isPrime(T n) {
		for(T i = 2; i <= sqrt(n); i++) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}

	// Check if the number given is in a vector by scanning it and returning if a result is found.
	template<typename T>
	bool isInVector(T n, std::vector<T> vec) {
		if(find(vec.begin(), vec.end(), n) != vec.end()) {
			return true;
		}
		return false;
	}

	// Check if the number is a prime by scanning a vector of numbers that are flagged at the relevant index if prime.
	template<typename T>
	bool isPrime(T n, std::vector<T> primes) {
		if(primes[n] == 1) {
			return true;
		}
		return false;
	}

	// Generate the primes upto N using the Sieve of Eratosthenes.
	template<typename T>
	std::vector<T> generatePrimes(T n) {
		std::vector<T> result = std::vector<T>();
		if(n < 2) {
			return result;
		}
		std::vector<int> input(n + 1, 1);
		// Calculates the upper limit of the numbers to check.
		T sqrtN = (T)sqrt(n);
		// Iterate till the square root.
		for(T i = 2; i <= sqrtN; i++) {
			if(!input[i]) {
				continue;
			}
			// Multiples are marked false.
			for(T j = i * i; j <= n; j += i) {
				input[j] = 0;
			}
		}
		// Add to result vector.
		result.push_back(2);
		for(T i = 3; i <= n; i += 2) {
			if(input[i]) {
				result.push_back(i);
			}
		}
		return result;
	}

	// Get vector of type T - containing true at the prime indexes and false otherwise.
	template<typename T>
	std::vector<T> generatePrimes(T N, bool reverse) {
		int t = (reverse) ? 0 : 1;
		int f = (reverse) ? 1 : 0;
		// Use the Sieve of Eratosthenes.
		std::vector<int> primes(N, f);
		primes[0] = primes[1] = f;
		std::fill(primes.begin() + 2, primes.end(), t);
		static const long long int sqrtLimit = std::sqrt(N) + 1;
		for(std::size_t i = 2; i < sqrtLimit; ++i) {
			if(primes[i]) {
				for(std::size_t j = i + i; j < N; j += i) {
					primes[j] = f;
				}
			}
		}
		return primes;
	}

	// Given a pair of iterators, scan the container and confirm that all items in it are the same value.
	template<typename ForwardIterator>
	constexpr bool allEqual(ForwardIterator first, ForwardIterator last) {
		for(auto it = first++; it != last; ++it) {
			if(*first != *it) {
				return false;
			}
		}
		return true;
	}

	// Generic function to find an element in vector and also its position, returns a pair of a bool and integer.
	template<typename T>
	std::pair<bool, int> findInVector(const std::vector<T> &vecOfElements, const T &element) {
		std::pair<bool, int> result;
		// Find given element in vector.
		auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
		if(it != vecOfElements.end()) {
			result.second = distance(vecOfElements.begin(), it);
			result.first = true;
		} else {
			result.first = false;
			result.second = -1;
		}
		return result;
	}

	// Obtains the sum of the digits of a given number.
	template<typename T, typename U>
	T sumOfDigits(U n) {
		T sum = 0;
		while(n != 0) {
			auto d = n % 10;
			sum += (T)d;
			n /= 10;
		}
		return sum;
	}

	// Obtains the number of digits in a given number.
	template<typename T, typename U>
	T digitCount(U n) {
		T count = 0;
		while(n != 0) {
			n /= 10;
			count++;
		}
		return count;
	}

	/*
	An incredibly quick way to calculate the GCD of two numbers using intrinsics.
	Mostly was curious on a really fast version of it.
	https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
	*/
	unsigned int gcd(unsigned int u, unsigned int v) {
		int shift;
		if(u == 0) {
			return v;
		}
		if(v == 0) {
			return u;
		}
		shift = __builtin_ctz(u | v);
		u >>= __builtin_ctz(u);
		do {
			v >>= __builtin_ctz(v);
			if(u > v) {
				unsigned int t = v;
				v = u;
				u = t;
			}
			v = v - u;
		} while(v != 0);
		return u << shift;
	}
}