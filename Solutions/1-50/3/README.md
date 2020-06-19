# Problem 3: [Largest Prime Factor](https://projecteuler.net/problem=3)

## Thoughts
Since we are only concerned with unique prime factors, we can use a [set](https://en.cppreference.com/w/cpp/container/set) to store the factors.

Prime factorization of a number can be gotten by doing the following steps:

1. Divide the number by `2` continuously until it is no longer even. (`2` is our first prime factor if number was originally even.)
2. Then we simply divide the number by remaining possible factors which are odd numbers from `3` to `sqrt(n)`.

Once we have all the factors, we simply just take the largest number from the set (the one stored at the end).