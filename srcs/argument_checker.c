#include "../includes/push_swap.h"

int	print_and_return_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	check_if_arguments_are_numbers(int list_length, char **list)
{
	int	i;

	while (--list_length > 0) 
	{
		i = 0;
		while (list[list_length][i])
		{
			if (list[list_length][i] == '-')
			{
				if (i != 0)
					return (1);
			}
			else if ((is_digit(list[list_length][i])) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}	

int check_arguments_requirement(int list_length, char **list)
{
	if (check_if_arguments_are_numbers(list_length, list) == 1)
		return (1);
	//Check if number is not int_max or int_min
	//Check if number does not appear twice
	return (0);
}
