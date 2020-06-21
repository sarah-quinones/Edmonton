# Problem 38: [Pandigital Multiples](https://projecteuler.net/problem=38)

## Thoughts
For this problem we can make a couple of observations:
1. The base number we are multiplying must be four digits, and it must start with `9`, in order to maximize the concated number.
2. Since a four digit number starting with `9` multipled by `2` will give us `5` digits, we never have to check for any `n > 2`.
   
Keeping both of these in mind, we just need to check all numbers from `9000` to `9999` and find the largest one that is pandigital.