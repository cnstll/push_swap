#include "../includes/push_swap.h"

int	print_and_return_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	check_if_arg_is_number(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if (argument[i] == '-')
		{
			if (i != 0)
				return (1);
		}
		else if ((is_digit(argument[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int check_if_arg_in_int_range(char *argument)
{
	int		i;
	unsigned int	number;

	i = 0;
	number = 0;
	
}

int check_arguments_requirement(int list_length, char **list)
{
	int	reverse_index;

	reverse_index = list_length;
	while (--reverse_index > 0) 
	{
		if (check_if_argument_is_number(list[reverse_index]) == 1)
			return (1);
		if (check_if_arg_in_int_range
	//Check if number is not int_max or int_min
	//Check if number does not appear twice
	return (0);
}
