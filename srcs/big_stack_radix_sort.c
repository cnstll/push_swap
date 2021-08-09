#include "../includes/push_swap.h"

static int	check_if_bit_is_one(int num, int bit_position)
{
	return ((num >> bit_position) & 1);
}

static int	most_significative_bit(int max_num)
{
	int	most_significative_bit_position;
	int	i;

	most_significative_bit_position = 0;
	i = 0;
	while (i < INT_SIZE)
	{
		if (((max_num >> i) & 1) == 1)
			most_significative_bit_position = i;
		i++;
	}
	return (most_significative_bit_position);
}

static int	stack_is_ordered(t_stack *stack_a, int bit_pos, int rotation_nb)
{
	int	i;

	i = stack_a->top;
	while (i < stack_a->size - rotation_nb)
	{
		if (check_if_bit_is_one(stack_a->stack[i], bit_pos) == 1)
			return (0);
		i++;
	}
	return (1);
}

static void	operate_stacks(t_stack *stack_a, t_stack *stack_b, int bit_to_sort)
{
	int	i;
	int	check;
	int	num_of_rotate;

	i = 0;
	check = 0;
	num_of_rotate = 0;
	while (i < stack_a->size && check == 0)
	{
		if (check_if_bit_is_one(stack_a->stack[stack_a->top], bit_to_sort))
		{
			rotate(stack_a, 'a');
			num_of_rotate++;
		}
		else
			push(stack_b, stack_a, 'b');
		i++;
		check = stack_is_ordered(stack_a, bit_to_sort, num_of_rotate);
	}
}

void	binary_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	j;
	int	nb_of_bits_to_sort;

	j = 0;
	nb_of_bits_to_sort = most_significative_bit(stack_a->size - 1);
	while (j <= nb_of_bits_to_sort)
	{
		operate_stacks(stack_a, stack_b, j);
		empty_stack(stack_a, stack_b, 'a');
		j++;
	}
}
