#include <cmath>
#include <vector>

// A collection of useful functions that I came up with when solving these problems and that are used often.
// Uses templates so it can be easy to get correct number type, including but not limited to boost.

namespace Edmonton {
    // Generate the n'th term in the Fibonacci sequence.
    template <typename T>
    T fib(T n) {
        if(n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    // Check if a number is a palindrome in the relevant base.
    template <typename T>
    bool isPalindrome (T n, T b) {
        T r = 0, t = n;
        // Reverse the number.
        while(n > 0) {
            r = (r * b) + n % b;
            n = n / b | 0;
        }
        return (r == t) ? true : false;
    }

    // When checking for prime numbers we only need to go till square root of n.
    template <typename T>
    bool isPrime(T n) {
        for(T i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Generate the first N primes using the Sieve of Eratosthenes.
    template <typename T>
    std::vector<T> generatePrimes(T n) {
        std::vector<T> result = std::vector<T>();
        if(n < 2) {
            return result;
        }
        std::vector<bool> input(n + 1, true);

        // Calculates the upper limit of the numbers to check.
        T sqrtN = (T)sqrt(n);

        // Iterate till the square root.
        for(T i = 2; i <= sqrtN; i++) {
            if(!input[i]) {
                continue;
            }

            // Multiples are marked false.
            for(T j = i * i; j <= n; j += i) {
                input[j] = false;
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
}