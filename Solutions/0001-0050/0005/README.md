# Problem 5: [Smallest Multiple](https://projecteuler.net/problem=5)

## Thoughts
The smallest possible number will be `20` and when we increment looking for the target, we can increment by 20 each time. The only check that is needed is to see if the number is evenly divisible by `11` through `19`. The numbers less than `10` will be guaranteed to evenly divide this number due to them evenly dividing into the upper half of the range.