# polymorphism basic concept

This project simulates the mutation of malware code represented by integers. The `IntegerMalware` (will prob change) class provides a method to mutate its code using various mutation techniques. The project demonstrates these mutations through a series of iterations.

### its kinda buggy sorry
[blog on how polymorphism works](https://0x00sec.org/t/what-the-frick-is-a-polymorphic-engine/41059)

## Features

- **Mutation Types**:
  - Increment a random element by a value between 10 and 50.
  - Replace a random element with a value between 1 and 100.
  - Swap two random elements.
  - Shuffle the entire code sequence.
  - Shift all elements up or down by a value between -5 and 5, ensuring no negative values.

## Requirements

- A C++17 compatible compiler (e.g., GCC, Clang, MSVC)

## Compilation

To compile the program, use the following command:

```g++ -std=c++17 -o main main.cpp```

## Examples
```
initial example code: 1 2 3 4 5
iteration 1: mutated example code: 1 2 3 52 5
iteration 2: mutated example code: 87 2 3 52 5
iteration 3: mutated example code: 87 2 3 52 47

initial example code: 1 2 3 4 5
iteration 1: mutated example code: 62 2 3 4 5
iteration 2: mutated example code: 62 46 3 4 5
iteration 3: mutated example code: 61 45 6 9 6

initial example code: 1 2 3 4 5
iteration 1: mutated example code: 1 2 96 4 5
iteration 2: mutated example code: 3 6 101 1 8
iteration 3: mutated example code: 3 6 101 1 31
