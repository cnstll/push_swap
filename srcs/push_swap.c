#include "../includes/push_swap.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	printf("Max int : %d -- Min int : %d\n", INT_MAX, INT_MIN);	
	if (argc == 1)
		return (print_and_return_error());
	else
	{
		if (check_arguments_requirement(argc, argv) == 1)
			return (print_and_return_error());
		else
		{
			write(1, "OK\n", 3);
			//sort_number_list(void);
			return (0);
		}
	}	
	(void)argv;
	return (0);
}
