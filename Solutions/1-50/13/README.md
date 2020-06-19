# Problem 13: [Large Sum](https://projecteuler.net/problem=13)

## Thoughts
This is the first problem in which the normal C++ numerical capabilities aren't sufficient. As such I decided to use the [boost](https://www.boost.org/) multi-precision library for large integer handling. Doing so it was fairly trivial to add up all numbers and then print the first ten digits of the sum.

The most useful thing of the process is probably the method to copy the file into a vector as such:

```cpp
ifstream input("Data.txt");
vector<cpp_int> numbers;
istream_iterator<cpp_int> end, start(input);
copy(start, end, back_inserter(numbers));
```