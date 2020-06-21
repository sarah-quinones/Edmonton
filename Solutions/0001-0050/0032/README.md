# Problem 32: [Pandigital Products](https://projecteuler.net/problem=32)

## Thoughts
This problem introduces the concept of pandigital numbers, so we need to check if the digits in a number are unique. The most obvious and expensive way is to convert them into a string after concating them together, and compare to a base string.

Those can easily be handled by two small helper functions like so:

```cpp
bool isPandigital(long n) {
	string b = "123456789";
	string r = to_string(n);
	sort(r.begin(), r.end());
	return (b == r);
}

long concat(long a, long b) {
	long c = b;
	while(c > 0) {
		a *= 10;
		c /= 10;
	}
	return a + b;
}
```

Then we just need to worry about the unique products that are generated, which we store in a set. The range for the two numbers we need to multiply in order to get only a required length of product is a multiplicand `n` from `1` to `100` and a multiplier `m` from `1` to less than `(10000 / n) + 1`.

