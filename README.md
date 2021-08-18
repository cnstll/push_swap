# push_swap
## Project Goal
Push swap aims at developping a program that sorts a list of numbers in ascending order.
The program receives the list in argument.
The sorting must be done using 2 stacks and a limited set of operations.
These operations are the following:  
* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.
The program must display each operation executed to sort the list.
The program efficiency is assessed on the number of operations printed to sort the list.
A program called "checker" is provided to verify that the list of operations effectively sorts the list.

## Use the program

To launch the program add the list of numbers to sort in argument.
```
$>./push_swap 2 1 3 6 5
ra
pb
rra
pb
sa
ra
pa
pa
```
To use the checker:
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
## Some notes on the program

* Lists from 2 to 5 numbers: I developped my own sorting algorithm as for 3 and 5 numbers list, a
max number was compulsory, respectively 3 and 12. 
* Lists from over 5 numbers: I used a LSD radix sort by breaking down numbers into their binary
equivalent. I use stack 1 as the 'ones' bucket and stack 2 as the "zeros" bucket. Each number is
sorted from its least significant binary digit to its most significant binary digit. Some
pre-sorting optimizations have been made such as checking if the list already sorted, replacing each
number by its sorted state position value (if "3414" were to end up in the 300th position in the
list when sorted, it would be replaced by "300" in the list. So if the list is 500 numbers long, the
max number handle would be 499).

## Reading notes
	cf. doc
