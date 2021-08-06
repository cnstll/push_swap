#include "../includes/push_swap.h"

static int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

static int	pre_check_one_arg(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (!is_spaces(arg[i]) && !is_digit(arg[i]) && !is_sign(arg[i]))
			return (1);
		if (is_sign(arg[i]))
			if (!arg[i + 1] || !is_digit(arg[i + 1]))
				return (1);
		if (is_digit(arg[i]))
			if (arg[i + 1] && is_sign(arg[i + 1]))
				return (1);
		i++;
	}
	return (0);
}

static int	pre_check_multiple_arg(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (!is_sign(arg[i]) && !is_digit(arg[i]))
			return (1);
		if (is_sign(arg[i]))
			if (!arg[i + 1] || !is_digit(arg[i + 1]))
				return (1);
		if (is_digit(arg[i]))
			if (arg[i + 1] && !is_digit(arg[i + 1]))
				return (1);
		i++;
	}
	return (0);
}

int	check_arguments_requirements(int nb_of_arg, char **arg)
{
	int	i;
	int	error;

	i = nb_of_arg;
	if (nb_of_arg == 2)
		return (pre_check_one_arg(arg[1]));
	else if (nb_of_arg > 2)
	{
		while (--i > 0)
		{
			if (pre_check_multiple_arg(arg[i]))
				return (1);
			error = 0;
			ft_atol(arg[i], &error);
			if (error < 0)
				return (1);
		}
	}
	return (0);
}
