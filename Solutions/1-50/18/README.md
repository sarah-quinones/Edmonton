# Problem 18: [Maximum Path Sum I](https://projecteuler.net/problem=18)

## Thoughts
Since this problem is the same as #67, there's no point bruteforcing this one if I'd have to solve that one correctly. As such the key to this problem is recognizing I can go from bottom up, and it essentially boils down to a dynamic-programming problem. We read all of the data into vectors, then add the larger of the two numbers at a location to the number above it. 

A demonstration of a smaller triangle is as follows:

    75
    95 64
    17 47 82

Then we take the bottom row and we see that between `17` and `47` we add the `47` to `95`. And so on. This leads to iterating the triangle as such:

    # Iteration 0
    75
    95 64
    17 47 82

    # Iteration 1
    75
    142 146

    # Iteration 2
    221

Applying this concept to both problems `18` and `67` using the same code, and they are solved.