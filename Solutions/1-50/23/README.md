# Problem 23: [Non-Abundant Sums](https://projecteuler.net/problem=23)

## Thoughts
Yet another boring problem that deals with divisors. Simply use the function(s) from earlier to calculate the sum of the divisors and generate all the abundant numbers. Then we loop through all abundant numbers and mark off everything that can be written as the sum of two of them. Whatever is left will be summed up for our answer.