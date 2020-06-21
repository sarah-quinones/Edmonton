# Problem 22: [Names Scores](https://projecteuler.net/problem=22)

## Thoughts
The only interesting part of this problem is getting the word scores, which turned out to be quite trivial. After doing that the only thing that remained was using a sorted list of names and calculating everything, then doing a simple summation.

The scoring function is as follows:

```cpp
int letterScore(string_view s) {
	int sum = 0;
	for(unsigned int i = 0; i < s.length(); i++) {
		sum += s[i] - 'A' + 1;
	}
	return sum;
}
```