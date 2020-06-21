# Problem 39: [Integer Right Triangles](https://projecteuler.net/problem=39)

## Thoughts
This problem is essentially just optimizing a bunch of the math out, so starting from what we know:

1. `a^2 + b^2 = c^2`
2. `a + b + c = p`
3. `p <= 1000`
4. If `a` and `b` are both even, or both are odd, then `c` is even, and `p` must be even.
5. If either `a` is even and `b` is odd, or vice versa, then `c` is odd and `p` is even.

So given that information you can calculate the maximum bounds of `a` and `b` by setting each to `0` and solving for other. So it ends up as `b <= 500` and `a <= 500` with `c` being remainder.

We can also see with some simple substitution that: `b = (p^2 - 2 * p * a) / (2 * (p - a))`

So as long as we get an integer out of `b`, then by subbing in the other two parameters we can get the triplets.

Since `p` is always even, we can skip all odd numbers and limit our search space.