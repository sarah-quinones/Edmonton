# Problem 12: [Highly Divisible Triangular Number](https://projecteuler.net/problem=12)

## Thoughts
Instead of summing up numbers to find the triangle numbers, we can get the n'th triangular number with a simple formula:

```cpp
constexpr int triangular(int n) {
    return (n * (n + 1)) / 2;
}
```

After that we can calculate the number of divisors a number has using prime factorization, and use that function to check until we find something with over 500 divisors.