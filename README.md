# push_swap - 42 Project

## Introduction

**push_swap** is a project at 42 that focuses on implementing an algorithm to sort a stack of integers using a limited set of operations. The goal is to develop efficient sorting algorithms and gain a deeper understanding of algorithmic complexity and stack operations.

You are required to create a program that sorts a stack of integers with minimal operations, utilizing a second stack to assist with sorting.

## Project Overview

The project involves:

- **Parsing**: Reading a list of integers from the command line.
- **Sorting Algorithm**: Implementing a sorting algorithm that efficiently sorts the integers using only the allowed stack operations.
- **Operations**: Using the following stack operations:
  - `sa` - Swap the top two elements of stack A.
  - `sb` - Swap the top two elements of stack B.
  - `ss` - Swap the top two elements of both stacks A and B.
  - `pa` - Push the top element of stack B to stack A.
  - `pb` - Push the top element of stack A to stack B.
  - `ra` - Rotate stack A (move the top element to the bottom).
  - `rb` - Rotate stack B (move the top element to the bottom).
  - `rr` - Rotate both stacks A and B.
  - `rra` - Reverse rotate stack A (move the bottom element to the top).
  - `rrb` - Reverse rotate stack B (move the bottom element to the top).
  - `rrr` - Reverse rotate both stacks A and B.

## Usage

1. Clone the repository and navigate to the project directory:

   ```bash
   git clone https://github.com/fclaus-g/push_swap.git
   cd push_swap
   ```

2. Compile the project using:

   ```bash
   make
   ```

3. Run the program with a list of integers to sort:

   ```bash
   ./push_swap 3 5 1 4 2
   ```

   The program will output the sequence of operations needed to sort the stack.

4. Optionally, you can use the provided `checker` program to test and verify your sorting algorithm:

   ```bash
   ./push_swap 3 5 1 4 2 | ./checker 3 5 1 4 2
   ```

   The `checker` program will check if the output from `push_swap` sorts the numbers correctly.

## Project Files

- **push_swap.c**: Contains the main sorting logic and command parsing.
- **stack_operations.c**: Implements the stack operations required by the algorithm.
- **utils.c**: Utility functions for handling input and managing stacks.
- **push_swap.h**: Header file with function prototypes and necessary includes.
- **Makefile**: Automates the compilation process.

## Example

```bash
./push_swap 4 3 2 1
```

Output might be:

```
pb
pb
pb
pb
ra
ra
ra
sa
pa
pa
pa
pa
```

This sequence of operations will sort the stack from `4 3 2 1` to `1 2 3 4`.

## License

This project is part of the 42 curriculum and is intended for educational purposes. Feel free to use it for learning, but be mindful of 42’s collaboration policies.
