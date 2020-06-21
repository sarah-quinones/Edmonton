# Problem 30: [Digit Fifth Power](https://projecteuler.net/problem=30)

## Thoughts
Few simple observations:
1. The upperbound on the numbers we need to check will be given by `6 * 9^5`, since this is the largest number that we can get as a result.
2. The lowerbound will be ten since we would like to exclude all single digit numbers from the results. 
3. If we cache the powers of the digits, there will be a minor speed increase.

Combining these three notes, we can write a quick loop that will check if the number meets the set critera.