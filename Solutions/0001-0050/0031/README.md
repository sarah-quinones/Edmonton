# Problem 31: [Coin Sums](https://projecteuler.net/problem=31)

## Thoughts
This can be solved as a dynamic programming problem, where we use the smaller solutions to compute up to a bigger one. The basic logic of the solution is that we can express any singular amount exactly one time with 1 pence coins. The next coin up, we can't make any change for value less than 2 pence, however we can create the difference between target and 2 pence. We can then iterate over the array following this pattern.

In essence what ends up happening is that for each coin value, we sarted with the current value and go to the target value. Each entry in the array then results in being the number of ways the amount can be expressed using that coin, plus the previous value. The result is then the value at the final item in the array.