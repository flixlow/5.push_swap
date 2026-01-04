_This project was created as part of the 42 curriculum by mobenhab and flauweri._

# 📌 Description

push_swap is a sorting algorithm project from the Codam / School 42 core curriculum.

The goal is to write a program in C that takes an unsorted list of integers and sorts them in ascending order using only:

two stacks (a and b)

a limited set of operations

The program outputs the exact sequence of moves required to sort the numbers.

Example:

./push_swap 3 2 1
sa
rra

# ⚙️ Instructions

# 🔧 Compilation

Run:

make


This will generate the push_swap executable.

# ▶️ Usage

Provide a list of integers:

./push_swap 3 2 1

# ✔️ Checking the result

Download the appropriate checker for your OS, then run:

./push_swap 3 2 1 | ./checker_linux 3 2 1


Expected output:

OK

# 🔁 Generate Random Lists for Testing
100 random numbers (0–1000):

ARG=$(shuf -i 0-1000 -n 100); ./push_swap $ARG | ./checker_linux $ARG

500 random numbers (0–10000):

ARG=$(shuf -i 0-10000 -n 500); ./push_swap $ARG | ./checker_linux $ARG

# 📏 Count the Number of Operations

Useful for evaluating performance:

ARG=$(shuf -i 0-1000 -n 100); ./push_swap $ARG | wc -l

# 📚 Resources


## Authors

- [@mobenhab](https://www.github.com/hicham-bnh)

- [@flauweri](https://www.github.com/flixlow)
