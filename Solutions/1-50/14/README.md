# Problem 14: [Longest Collatz Sequence](https://projecteuler.net/problem=14)

## Thoughts
This is a fairly well known problem and has a simple recurisve function that essentially amounts to something similar to this:

```cpp
unsigned int chain_length = 0;
if(n % 2 == 0) {
    chain_length = collatz(n / 2) + 1;
} else {
    chain_length = collatz((3 * n) + 1) + 1;
}
```

However when actually trying to do some of these chains, they can get quite long, and use many repeated parts, so it makes sense to make use of [memoization](https://en.wikipedia.org/wiki/Memoization) to retrieve sections of the chain we have calculated before and stored in a cache which is implemented by using a [map](https://en.cppreference.com/w/cpp/container/map).