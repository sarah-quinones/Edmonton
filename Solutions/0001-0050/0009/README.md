# Problem 9: [Special Pythagorean Triplet](https://projecteuler.net/problem=9)

## Thoughts
There's not much to actually think about for this problem. Just a few simple observations that:

1. The relative position of the numbers as `a`, `b`, `c` doesn't matter. 
2. The Pythagorean check can be written as `(c * c) - (b * b)) == (a * a)`.

Then we just wrap it up in some loops and we have our answer.