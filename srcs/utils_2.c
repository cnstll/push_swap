#include "../includes/push_swap.h"

void	free_2d_string(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	number_of_substrings(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strdup_till_char(char *s, char c, int start)
{
	int		i;
	int		size;
	char	*dup;

	i = start;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	size = i - start;
	dup = (char *)(malloc(sizeof(char) * (size + 1)));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < size)
		dup[i++] = s[start++];
	dup[i] = '\0';
	return (dup);
}

static int	verify_not_only_sep(char *str, int current_index, char sep)
{
	while (str[current_index])
	{
		if (str[current_index] != sep)
			return (1);
		current_index++;
	}
	return (0);
}

char	**lite_split(char *s, char c)
{
	char	**ret;
	int		j;
	int		k;
	int		nb_of_separator;

	j = -1;
	nb_of_separator = 0;
	while (s && s[++j])
		if (s[j] != c && s[j + 1] == c && verify_not_only_sep(s, j + 1, c))
			nb_of_separator++;
	j = 0;
	k = 0;
	ret = (char **)malloc(sizeof(char *) * (nb_of_separator + 2));
	while (ret && j <= nb_of_separator)
	{
		while (s[k] == c)
			k++;
		ret[j] = ft_strdup_till_char(s, c, k);
		while (s[k] && s[k] != c)
			k++;
		j++;
	}
	if (ret)
		ret[j] = 0;
	return (ret);
}
