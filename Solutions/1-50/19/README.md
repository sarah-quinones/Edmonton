# Problem 19: [Counting Sundays](https://projecteuler.net/problem=19)

## Thoughts
We can calculate the day of the week as a number by using [Zeller's congruence](https://en.wikipedia.org/wiki/Zeller%27s_congruence#). We can then run through all years and months and check if the first is a Sunday, thus adding it to the counter.