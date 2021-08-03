#include "../includes/push_swap.h"

static int	make_partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

static void	quick_sort(int	*arr, int start, int end)
{
	int	partition_index;

	if (start < end)
	{
		partition_index = make_partition(arr, start, end);
		quick_sort(arr, start, partition_index - 1);
		quick_sort(arr, partition_index + 1, end);
	}
}

static void	copy_array(int *src_arr, int *dest_arr, int arr_size)
{
	int i;

	i = 0;
	while (i < arr_size)
	{
		dest_arr[i] = src_arr[i];
		i++;
	}
}

static void	remove_negative_num(int *ordered_arr, int *src_arr, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size)
		{
			if (src_arr[i] == ordered_arr[j])
			{
				src_arr[i] = j;
				j = 7;
			}
			j++;
		}
		i++;
	}
}

void	pre_sort_stack(t_stack *stack_a, int list_size)
{
	t_stack	copy;

	copy.stack = ft_calloc(list_size, sizeof(int));
	copy.size = list_size;
	copy.top = 0;
	copy.is_empty = 0;
	copy_array(stack_a->stack, copy.stack, stack_a->size);
	quick_sort(copy.stack, 0, copy.size - 1);
	remove_negative_num(copy.stack, stack_a->stack, list_size);
	free(copy.stack);
}
