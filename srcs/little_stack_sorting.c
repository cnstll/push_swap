#include "../includes/push_swap.h"

void	stack_of_three_sorting(t_stack *sa)
{
	int	t;

	t = sa->top;
	while (sa->stack[t] > sa->stack[t + 1]
			|| sa->stack[t + 1] > sa->stack[t + 2])
	{
		if (sa->stack[t] < sa->stack[t + 1] &&
		sa->stack[t + 1] > sa->stack[t + 2] && sa->stack[t] > sa->stack[t + 2])
			reverse_rotate(sa, 'a');
		else if (sa->stack[t] > sa->stack[t + 1] &&
		sa->stack[t + 1] < sa->stack[t + 2] && sa->stack[t] > sa->stack[t + 2])
			rotate(sa, 'a');
		else
			swap_stacks(sa->stack, sa->top, 'a');
	}
}

static int find_list_min_value_index(t_stack *stack)
{
	int list_min;
	int min_value_index;
	int	i;

	list_min = stack->stack[stack->top];
	i = stack->top + 1;
	min_value_index = 0;
	while (i < stack->size)
	{
		if (list_min > stack->stack[i])
		{
			list_min = stack->stack[i];
			min_value_index = i - stack->top;
		}
 		i++;
	}
	return (min_value_index);
}

static void sort_stack_of_four_and_five(t_stack *sa, t_stack *sb)
{
	int	min_value_index;
	int	i;

	while (sa->current_size > 3)
	{
		min_value_index = find_list_min_value_index(sa);
		if (min_value_index <= sa->current_size / 2)
		{
			while (min_value_index-- > 0)
				rotate(sa, 'a');
			push(sb, sa, 'b');
		}
		else
		{
			i = sa->current_size - min_value_index;
			while (i-- > 0)
				reverse_rotate(sa, 'a');
			push(sb, sa, 'b');
		}
	}
	stack_of_three_sorting(sa);
	while (!sb->is_empty)
		push(sa, sb, 'a');
}

void	little_stack_sorting(t_stack *sa, t_stack *sb)
{
	if (sa->size == 2)
	{
		if (sa->stack[0] > sa->stack[1])
			swap_stacks(sa->stack, sa->top, 'a');
	}
	else if (sa->size == 3)
		stack_of_three_sorting(sa);
	else if (sa->size > 3)
		sort_stack_of_four_and_five(sa, sb);
	else
		;
}
