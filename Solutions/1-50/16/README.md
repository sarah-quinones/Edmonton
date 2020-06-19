# Problem 16: [Power Digit Sum](https://projecteuler.net/problem=16)

## Thoughts
We need to calculate the sum of the digits of a number. The easiest method is to loop through the number and just take off one digit at a time using the modulus operation and adding it to a running sum. Then divide the number by ten to remove the digit, and keep going.

Since `2^1000` is a massive number, easiest way to handle it is using the big integer library from boost, as well as the associated [`exponention`](https://www.boost.org/doc/libs/1_73_0/boost/math/special_functions/pow.hpp) function.