# Problem 35: [Circular Primes](https://projecteuler.net/problem=35)

## Thoughts
The two main points to this problem that are new are cutting off the last digit of a natural number, and shifting it to the left. In that vein it boils down to two equations:

```cpp
int left = floor(log10(n)) + 1;
int power = pow(10, left) - 1;
```

After that to go through all rotations of a number, we iterate from `1` to `left - 1`. After each iteration our new number can be calculated with: ```(n + n % 10 * power) / 10```. The rest is just checking if all rotations are prime, and if so increasing the count of circular primes.