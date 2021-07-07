#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

int	print_and_return_error(void);
int check_arguments_requirement(int list_length, char **list);
int	check_if_arguments_are_numbers(int list_length, char **list);
int	is_digit(char character);

#endif
