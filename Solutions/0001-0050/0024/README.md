# Problem 24: [Lexicographic Permutations](https://projecteuler.net/problem=24)

## Thoughts
Luckily for us C++ has a [handy built in function](https://en.cppreference.com/w/cpp/algorithm/next_permutation) that will generate the next lexicographic permutation of a given string.

This in turn boils the problem down to simply doing the following:
```cpp
string digits = "0123456789";
for(int i = 1; i < 1'000'000; i++) {
    next_permutation(digits.begin(), digits.end());
}
```