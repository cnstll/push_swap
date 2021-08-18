NAME = push_swap

SRCS = srcs/push_swap.c \
	   srcs/argument_checker.c \
	   srcs/utils_1.c \
	   srcs/utils_2.c \
	   srcs/utils_3.c \
	   srcs/utils_4.c \
       srcs/big_stack_pre_sorting.c \
       srcs/big_stack_radix_sort.c \
       srcs/little_stack_sorting.c \
       srcs/stack_operations_1.c \
       srcs/stack_operations_2.c

OBJS = $(SRCS:.c=.o)

UNAME_S := $(shell uname -s)
   ifeq ($(UNAME_S),Linux)
        CC=clang-9
    endif
    ifeq ($(UNAME_S),Darwin)
        CC=clang
    endif

CFLAGS = -Wall -Wextra -Werror

GFLAG = -g3 -fsanitize=address

INCLUDES= -I includes/

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS) $(INCLUDES)

debug :
	$(CC) $(CFLAGS) $(GFLAG) -o $(NAME) $(SRCS)

clean :
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
