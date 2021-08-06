#include "../includes/push_swap.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	check_duplicates(int *list, int list_size)
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

int	is_sorted(int *list, int list_size)
{
	int	i;

	i = 0;
	while (i < list_size - 1)
	{
		if (list[i] > list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	print_and_return_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
