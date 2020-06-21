# Problem 4: [Largest Palindrome Product](https://projecteuler.net/problem=4)

## Thoughts
For this problem we need to check if a given number is a palindrome. The conventional way to do this is simply use a while loop and reverse the digits of the integer. Since we need to obtain the largest palindrome from the product of two three-digit numbers, we can go backwards and check the palindromes. i.e `1000` to `1`. After we find the first one we only need to check palindromes for the ones after if and only if the product is larger. 

The palindrome check is easy to implement as a lambda as follows:
```cpp
constexpr auto is_palindrome = [](int n) {
    int r = 0, t = n;
    while(n != 0) {
        int remainder = n % 10;
        r = (r * 10) + remainder;
        n /= 10;
    }
    return (r == t) ? true : false;
};
```