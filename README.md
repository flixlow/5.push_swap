_This project was created as part of the 42 curriculum by mobenhab and flauweri._

# 📌 Description

push_swap is a sorting algorithm project from the Codam / School 42 core curriculum.

The goal is to write a program in C that takes an unsorted 
list of integers and sorts them in ascending order using only:

- two stacks (a and b)
- a limited set of operations

The program outputs the exact sequence of moves required to sort the numbers.

Example:

```./push_swap 3 2 1```\
sa\
rra

# ⚙️ Instructions

## 🔧 Compilation

to compile the project : 

- ```make```

This will generate the push_swap executable.

## ▶️ Usage

Provide a list of integers:

- as arguments: ```./push_swap 3 2 1```
- as a single string separed by space: ```./push_swap "3 2 1"```

Optional strategy selector:
- Forces the use of O(n2) algorithm: ```--simple```
- Forces the use of O(n√n) algorithm.: ```--medium```
- Forces the use of O(n log n) algorithm: ```--complex```
- Forces the use adaptive algorithm based on disorder: ```--adaptive```

Benchmark mode displays, after sorting: ```--bench```

- The computed disorder (% with two decimals).
- The name of the strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).

## ✔️ Checking the result

Download the appropriate checker for your OS in the repository, then run:

```./push_swap 3 2 1 | ./checker_linux 3 2 1```

Expected output: ```OK```

## 🔁 Generate Random Lists for Testing

100 random numbers (0–1000): 

```ARG=$(shuf -i 0-1000 -n 100); ./push_swap $ARG | ./checker_linux $ARG```

500 random numbers (0–10000): 

```ARG=$(shuf -i 0-10000 -n 500); ./push_swap $ARG | ./checker_linux $ARG```

## 📏 Count the Number of Operations

Useful for evaluating performance: ```ARG=$(shuf -i 0-1000 -n 100); ./push_swap $ARG | wc -l```

# 📚 Resources


- AI was used to discuss about algorithm choice, display float, 
memset for struct, git help, structuring the README.

- AI was not used to generate or debug the project code.

# algorithm selected

1. Simple Algorithm – O(n²): Insertion Sort–like strategy

	For small stacks, a strategy similar to insertion sort is used. Elements are moved one by one to their correct position using basic stack operations (sa, ra, rra, pa, pb).

	- Efficient for very small inputs (e.g. ≤ 5 elements)
	- Minimal number of operations
	- Easy to optimize manually

2. Medium Algorithm – O(n√n): Chunk-Based Sorting

	The stack is divided into chunks of size √n (or a fixed number of chunks depending on input size). Elements belonging to the current chunk are pushed to stack B, then reinserted into A in sorted order.

	- Reduces unnecessary rotations
	- Balances number of pushes and rotations
	- Much more efficient than quadratic strategies
	- Widely used for inputs around 100–500 elements

3. Complex Algorithm – ~O(n log n): Radix Sort (Binary / LSD)

	Radix sort is adapted for push_swap by indexing the values and sorting them bit by bit using binary representation. Elements are pushed between stacks based on the current bit.

	- Predictable number of operations
 	- Performs well on large inputs (e.g. 500+)
	- Uses only allowed stack operations

## Authors & Contributions

### [@mobenhab](https://www.github.com/hicham-bnh)

#### Precedent projects imported:

-	ft_atoi
-	ft_strcpy
- 	ft_strcmp

#### Features contribution:

-	chunks_sort
-	radix_sort
-	adaptive
-	operations
-	free all
-	init_stack

### [@flauweri](https://www.github.com/flixlow)

#### Precedent projects imported:

-	ft_printf
-	ft_itoa
-	ft_split

#### Features contribution:

-	Simple_sort
-	algo_choice
-	adaptive
-	Benchmark mode
-	parsing
-	error detection