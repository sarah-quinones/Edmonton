# Problem 7: [10001st Prime](https://projecteuler.net/problem=7)

## Thoughts
In order to find the n'th prime number, we need to check if a given number is prime. That can be done trivially by dividing a number by one to it's square root as such:

```cpp
bool is_prime(int n) {
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}
```

After that we just keep checking numbers and keeping track of which prime it is, stopping at the 10'001st.