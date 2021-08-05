#include "../includes/push_swap.h"

void	swap_stacks(int *stack, int top, char stack_name)
{
	int	tmp;

	tmp = stack[top];
	stack[top] = stack[top + 1];
	stack[top + 1] = tmp;
	if (stack_name)
	{
		write(1, "s", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *dest_stack, t_stack *src_stack, char stack_name)
{
	if (!src_stack->is_empty)
	{
		dest_stack->top--;
		dest_stack->current_size = dest_stack->size - dest_stack->top;
		dest_stack->stack[dest_stack->top] =
			src_stack->stack[src_stack->top];
		src_stack->top++;
		src_stack->current_size = src_stack->size - src_stack->top;
		src_stack->is_empty = check_if_empty(src_stack);
		dest_stack->is_empty = check_if_empty(dest_stack);
	}
	if (stack_name)
	{
		write(1, "p", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack *stack, char stack_name)
{
	int tmp;
	int	i;

	tmp = stack->stack[stack->top];
	i = stack->top;
	while(i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = tmp;
	if (stack_name)
	{
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	empty_stack(t_stack *dest_stack, t_stack *src_stack, char stack_name)
{
	while (check_if_empty(src_stack) != 1)
		push(dest_stack, src_stack, stack_name);
}

int	check_if_empty(t_stack *stack)
{
	return (stack->top == stack->size);
}
