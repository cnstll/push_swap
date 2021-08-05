#include "../includes/push_swap.h"

static int	*create_list_from_one_arg(char **arg_list, int *list_size)
{
	int		*new_list;
	int		i;
	char	**separated_arg;
	int		error;

	i = -1;
	error = 0;
	separated_arg = lite_split(arg_list[1], ' ');
	while (separated_arg[++i])
		ft_atol(separated_arg[i], &error);
	if (error < 0)
		return (NULL);
	*list_size = number_of_substrings(separated_arg);
	new_list = (int *)malloc(sizeof(int) * *list_size);
	i = -1;
	while (new_list && separated_arg[++i])
		new_list[i] = ft_atol(separated_arg[i], &error);
	free_2d_string(separated_arg);
	return (new_list);
}

static int	*create_list(int num_of_arg, char **arg_list, int *list_size)
{
	int		*new_list;
	int		i;
	int		error;

	i = -1;
	error = 0;
	new_list = NULL;
	if (num_of_arg > 2)
	{
		*list_size = num_of_arg - 1;
		new_list = (int *)malloc(sizeof(int) * *list_size);
		while (new_list && ++i < *list_size && error == 0)
			new_list[i] = ft_atol(arg_list[i + 1], &error);
		if (error < 0)
		{
			free(new_list);
			new_list = NULL;
			return (new_list);
		}
	}
	else
		new_list = create_list_from_one_arg(arg_list, list_size);
	return (new_list);
}

static int	check_duplicates_in_list(int *list, int list_size)
{
	int	i;
	int	k;

	i = 0;
	while (i < list_size)
	{
		k = i + 1;
		while (k < list_size)
		{
			if (list[i] == list[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

static void	sort_list(int *list, int list_size)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.stack = list;
	stack_a.size = list_size;
	stack_a.top = 0;
	stack_a.current_size = stack_a.size - stack_a.top;
	stack_a.is_empty = 0;
	stack_b.stack = ft_calloc(list_size, sizeof(int));
	stack_b.size = list_size;
	stack_b.top = list_size;
	stack_b.current_size = stack_b.size - stack_b.top;
	stack_b.is_empty = 1;
	if (stack_a.size <= 5)
		little_stack_sorting(&stack_a, &stack_b);
	else
	{
		pre_sort_stack(&stack_a, list_size);
		binary_radix_sort(&stack_a, &stack_b);
	}
	free(stack_b.stack);
}

int main(int argc, char *argv[])
{
	int *list;
	int list_size;

	if (argc == 1)
		return (print_and_return_error());
	else
	{
		if (check_arguments_requirements(argc, argv) == 1)
			return (print_and_return_error());
		else
		{
			list_size = 0;
			list = create_list (argc, argv, &list_size);
			if (list == NULL)
				return (print_and_return_error());
			if (check_duplicates_in_list(list, list_size))
			{
				free(list);
				return (print_and_return_error());
			}
			sort_list(list, list_size);
			free(list);
			return (0);
		}
	}
}
