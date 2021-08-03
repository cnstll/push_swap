#include "../includes/push_swap.h"

void	stack_of_three_sorting(t_stack *sa)
{
	while (sa->stack[sa->top] > sa->stack[sa->top + 1] || sa->stack[sa->top + 1] > sa->stack[sa->top + 2])
	{
		if (sa->stack[sa->top] < sa->stack[sa->top + 1] && sa->stack[sa->top + 1] > sa->stack[sa->top + 2]
		&& sa->stack[sa->top] > sa->stack[sa->top + 2])
			reverse_rotate(sa, 'a');
		else if (sa->stack[sa->top] > sa->stack[sa->top + 1] && sa->stack[sa->top + 1] < sa->stack[sa->top + 2]
		&& sa->stack[sa->top] > sa->stack[sa->top + 2])
			rotate(sa, 'a');
		else
			swap_stacks(sa->stack, sa->top, 'a');
	}
}

void	little_stack_sorting(t_stack *sa, t_stack *sb)
{
	int	counter;
	int	k;

	counter = 0;
	if (sa->size == 2)
	{
		if (sa->stack[0] > sa->stack[1])
			swap_stacks(sa->stack, sa->top, 'a');
	}
	else if (sa->size == 3)
		stack_of_three_sorting(sa);
	else if (sa->size > 3)
	{
		while (sa->size - sa->top > 3)
			push(sb, sa, 'b');
		stack_of_three_sorting(sa);
		while (!sb->is_empty)
		{
			while (sb->stack[sb->top] > sa->stack[sa->top + counter]
			&& counter <= sa->size - sa->top)
					counter++;
			if (counter <= (sa->size - sa->top) / 2 || counter == sa->size - sa->top)
			{
				k = counter;
				while (k-- > 0)
					rotate(sa, 'a');
				push(sa, sb, 'a');
				while (k++ < counter)
					reverse_rotate(sa, 'a');
			}
			else
			{
				k = sa->size - sa->top - counter + 1;
				counter = k;
				while (k-- > 0)
					reverse_rotate(sa, 'a');
				push(sa, sb, 'a');
				while (k++ < counter)
					rotate(sa, 'a');
			}
		}
	}
	else
		;
}
