# Push Swap - an exercise in sorting stacks
This project was created to solve the following problem: Given a random number of integers, create a program that sorts them with
the fewest amount of moves possible. Rules: No integer is repeated; The numbers exist in a stack and we can use an additional stack
to sort them.
Available moves:
- sa (swap a): Swap the first 2 elements at the top of stack a; Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

## How to create it:

```
	git clone https://github.com/daalmeid/push_swap.git
	cd push_swap
	make
```

The output will be the name of the moves executed. To check if the stack is sorted, you can use the checker the following way:
```
>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
The checker will give an OK or a KO as the output. Alternatively, you can use the visualizer created by the user 
[o-reo](https://github.com/o-reo/push_swap_visualizer). All credits go to this user, amazing work.
