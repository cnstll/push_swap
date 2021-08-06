#include "../includes/push_swap.h"

int	has_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (is_digit(str[i++]))
			return (1);
	return (0);
}
