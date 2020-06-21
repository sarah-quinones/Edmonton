# Problem 33: [Digit Cancelling Fractions](https://projecteuler.net/problem=33)

## Thoughts
If our resulting numerator and denominator are `1 <= n < d <= 9` and the number we are cancelling is `1 <= c <= 9`. Then it follows that `n/d < 1`. Finally we just have to check that if `((n * 10 + c) * d) == ((c * 10 + d) * n))`, We have one of our required fractions.
