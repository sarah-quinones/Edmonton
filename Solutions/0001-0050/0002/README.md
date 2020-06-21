# Problem 2: [Even Fibonacci numbers](https://projecteuler.net/problem=2)

## Thoughts
Fibonacci numbers are created by adding the previous two terms in the sequence. For this problem we start from `1` and `2`. Thus the first ten terms are: 

```
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... 
```

In order to calculate them we can come up with a simple function that calculates the n'th term recursively.

```cpp
template<typename T>
T fib(T n) {
	if(n <= 1) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}
```

The rest of the problem is simply generating terms until the value returned is greater than four million, and adding up the even terms.