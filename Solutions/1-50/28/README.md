# Problem 28: [Number Spiral Diagonals](https://projecteuler.net/problem=28)

## Thoughts
The numbers of the diagonals must follow a simple pattern, so given the sample starting grid we can figure out the formula for each diagonal.

The given grid is:
```
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
```

Top Right:
```
9, 25, 49 => 4n^2 + 4n  + 1 
```
Bottom Left: 
```
5, 17, 37.. => 4n^2 + 1
```
Top Left: 
```
7, 21, 43.. => 4n^2 + 2n + 1
```
Bottom Right: 
```
3, 13, 31.. => 4n^2 - 2n + 1
```


Thus given any number `N`, we can get the value for each diagonal and sum them all up, and then add `1` at end and get the final result.