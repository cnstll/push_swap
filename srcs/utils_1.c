#include "../includes/push_swap.h"

int	is_digit(char character)
{
	return (character >= '0' && character <= '9');
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_spaces(char c)
{
	return (c == '\t' || c == ' ');
}

int	is_within_int_range(long long int number, int sign)
{
	if (sign < 0)
		return ((number * sign) >= INT_MIN);
	else
		return (number <= INT_MAX);
}

long long	ft_atol(char *str, int *error)
{
	int			sign;
	long long	n;
	int			i;

	i = 0;
	n = 0;
	sign = 1;
	while (is_spaces(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = sign * (-1);
	while (is_digit(str[i]) && is_within_int_range(n, sign))
	{
		if (is_digit(str[i + 1]))
			n = (n + (long long)(str[i]) % 48) * 10;
		else
			n = (n + (long long)(str[i]) % 48);
		i++;
	}
	if (!is_within_int_range(n, sign))
		*error = -1;
	return (n * sign);
}
