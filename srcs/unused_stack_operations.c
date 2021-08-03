void	reverse_rotate_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	write(1, "rr", 2);
	write(1, "\n", 1);
}

void	rotate_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr", 2);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *stack, char stack_name)
{
	int tmp;
	int	i;

	tmp = stack->stack[stack->size - 1];
	i = stack->size - 1;
	while(i > stack->top)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = tmp;
	if (stack_name != 0)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	swap_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	swap_stacks(stack_a->stack, stack_a->top, 0);
	swap_stacks(stack_b->stack, stack_b->top, 0);
	write(1, "ss", 2);
	write(1, "\n", 1);
}
