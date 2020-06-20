# Problem 26: [Reciprocal Cycles](https://projecteuler.net/problem=26)

## Thoughts
There are two main interesting observations that can be had for the example:

1. Each of the recurring cycles ends once a digit it has encountered before shows up again. 
2. The number must be odd (and prime).

We can wrap these two ideas up into a simple set of loops to calculate the length of each recurrence.