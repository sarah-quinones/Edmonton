# Problem 21: [Amicable Numbers](https://projecteuler.net/problem=21)

## Thoughts
We already know how to calculate the divisors of a number, so we wrap that up in a neat function and have it return the sum of said divisors. Finding the sum of all amicable numbers is then as trivial as inserting them into a set (in order to avoid double counting) as they pop up and then running a quick sum using [`std::accumulate`](https://en.cppreference.com/w/cpp/algorithm/accumulate).