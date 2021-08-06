#include "../includes/push_swap.h"

void	reverse_rotate(t_stack *stack, char stack_name)
{
	int	tmp;
	int	i;

	tmp = stack->stack[stack->size - 1];
	i = stack->size - 1;
	while (i > stack->top)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = tmp;
	if (stack_name)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}
