# Problem 11: [Largest Product in a Grid](https://projecteuler.net/problem=11)

## Thoughts
For this problem there is a `20 * 20` grid. We need the diagonals and the horizontal/vertical products. Assuming we start from point `(0, 0)`. The maximum we need to iterate is till point `(17, 17)`. Everything beyond that will fall out of range if we try and extend our `4` numbers past that point.

The actual problem itself is just going to each number and calculating the product using it's neighbours, then finding the maximum product between all directions, and then comparing against the current maximum found for the problem.