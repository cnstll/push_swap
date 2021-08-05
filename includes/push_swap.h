#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../testing/tester.h"
# define INT_SIZE 32
# define LIST_SIZE 100

typedef struct	s_stack
{
	int	*stack;
	int	size;
	int	top;
	int	current_size;
	int	is_empty;
}				t_stack;

int		check_if_empty(t_stack *stack);
void	swap_stacks(int *stack, int top, char stack_name);
void	push(t_stack *dest_stack, t_stack *src_stack, char stack_name);
void	rotate(t_stack *stack, char stack_name);
void	empty_stack(t_stack *dest_stack, t_stack *src_stack, char stack_name);
void	pre_sort_stack(t_stack *stack_a, int list_size);
void	binary_radix_sort(t_stack *stack_a, t_stack *stack_b);
void	swap(int *a, int *b);
char	**lite_split(char *s, char c);
int		print_and_return_error(void);
int		check_arguments_requirements(int nb_of_arg, char **arg);
int		is_digit(char character);
void	free_2d_string(char **s);
int		number_of_substrings(char **str);
long long	ft_atol(char *str, int *error);
void		*ft_calloc(size_t nmemb, size_t size);
int	is_spaces(char c);
void	reverse_rotate(t_stack *stack, char stack_name);
void	little_stack_sorting(t_stack *stack_a, t_stack *stack_b);

#endif
