# Problem 8: [Largest Product in a Series](https://projecteuler.net/problem=8)

## Thoughts
Since C++ doesn't have a native way of handling a thousand digit integer, the best way to probably handle this is to treat it as a string. Then we can employ a function to go over a range of characters given a start and endpoint, convert the characters to integers and calculate the product.

```cpp
long long product(string_view s, int start, int n) {
	long long prod = 1;
	for(auto it = s.begin() + start; it < (s.begin() + start + n); it++) {
		prod *= (*it - '0');
	}
	return prod;
}
```

After that we just have to loop through the string and find the maximum product using [`std::max`](https://en.cppreference.com/w/cpp/algorithm/max).