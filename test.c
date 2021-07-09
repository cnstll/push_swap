#include <stdio.h>
#define LIST_SIZE 5

typedef struct	s_stack
{
	int	*stack;
	int	size;
	int	top;
	int	is_empty;
}				t_stack;

void	print_result(int *sorted_list, int list_size)
{
	int	i;

	i = 0;
	while (i < list_size)
	{
		printf("%d ", sorted_list[i]);
		i++;
	}
	printf("\n");
}

int	check_if_empty(t_stack *stack)
{
	return (stack->top == stack->size);
}

void	swap(int *stack, int top)
{
	int	tmp;

	tmp = stack[top];
	stack[top] = stack[top + 1];
	stack[top + 1] = tmp;
}

void	swap_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a->stack, stack_a->top);
	swap(stack_b->stack, stack_b->top);
}


void	push(t_stack *destination_stack, t_stack *origine_stack)
{
	if (!origine_stack->is_empty)
	{
		destination_stack->top--;
		destination_stack->stack[destination_stack->top] =
			origine_stack->stack[origine_stack->top];
		origine_stack->top++;
		origine_stack->is_empty = check_if_empty(origine_stack);
		destination_stack->is_empty = check_if_empty(destination_stack);
	}
}

//top element of stack comes on bottom of the stack
void	rotate(t_stack *stack)
{
	int tmp;
	int	i;

	tmp = stack->stack[stack->top];
	i = stack->top;
	while(i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = tmp;
}

void	rotate_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

//bottom element of stack comes on top of the stack
void	reverse_rotate(t_stack *stack)
{
	int tmp;
	int	i;

	tmp = stack->stack[stack->size - 1];
	i = stack->size - 1;
	while(i > stack->top)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = tmp;
}

void	reverse_rotate_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	while (!check_if_empty(stack_a))
	{
		push(stack_b, stack_a);
		tmp = stack_b->stack[stack_b->top];
		if (!check_if_empty(stack_a) && tmp > stack_a->stack[stack_a->top])
			push(stack_a, stack_b);
		push(stack_b, stack_a);
	}
}

int main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.stack = (int [LIST_SIZE]){21, 3, 14, -5, 233};
	stack_a.size = LIST_SIZE;
	stack_a.top = 0;
	stack_a.is_empty = 0;
	stack_b.stack = (int [LIST_SIZE]){0};
	stack_b.size = LIST_SIZE;
	stack_b.top = LIST_SIZE;
	stack_b.is_empty = 1;
	//rotate(&stack_b);
	//reverse_rotate(&stack_b);
	//print_result(stack_a.stack, stack_a.size);
	//if (stack_a.top < stack_a.size - 1)
	//
	//	swap(stack_a.stack, stack_a.top);
	//	print_result(stack_a.stack, stack_a.size);
	//}
	printf("STACK START\n");
	print_result(stack_a.stack, stack_a.size);
	print_result(stack_b.stack, stack_b.size);
	printf("------------------------------\n");
	//push(&stack_b, &stack_a);
	//reverse_rotate_both_stack(&stack_a, &stack_b);
	sort(&stack_a, &stack_b);
	printf("STACK END\n");
	print_result(stack_a.stack, stack_a.size);
	print_result(stack_b.stack, stack_b.size);
	printf("------------------------------\n");
	printf("a is_empty ? %d\n", stack_a.is_empty);
	//print_result(stack_b.stack, stack_b.size);
	printf("b is_empty ? %d\n", stack_b.is_empty);
	return (0);
}
