# Problem 36: [Double-Base Palindromes](https://projecteuler.net/problem=36)

## Thoughts
Although there was a previous problem with palindromes, we couldn't use that function because it would not work in base two, so we have to extend the function to work with any base. Luckily the changes are quite trivial.

```cpp
constexpr bool is_palindrome = [](int n, int b) {
    int r = 0, t = n;
    // Reverse the number.
    while(n > 0) {
        r = (r * b) + n % b;
        n = n / b | 0;
    }
    return (r == t) ? true : false;
};
```