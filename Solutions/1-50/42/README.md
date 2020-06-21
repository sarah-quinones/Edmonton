# Problem 42: [Coded Triangle Numbers](https://projecteuler.net/problem=42)

## Thoughts
For this problem we can use the word score function that we came up with a bit ago, and couple it with a simple check to see if a number is triangular, which can be done as follows:

```cpp
bool isTriangular(int n) {
	int s = sqrt(2 * n);
	int c = s * (s + 1) / 2;
	return (c == n);
}
```
After that it is simply a matter of looping over the wordlist and keeping count.