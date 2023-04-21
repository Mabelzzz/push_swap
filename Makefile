NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = -Imlx

SRCS = 	srcs/check_error.c \
		srcs/ft_atoi.c \
		srcs/ft_split.c \
		srcs/get_input.c \
		srcs/oprt_push.c \
		srcs/oprt_rerotate.c \
		srcs/oprt_rotate.c \
		srcs/oprt_swap.c \
		srcs/sort_three.c \
		srcs/push_swap.c \
		srcs/utils_lst.c \
		srcs/utils.c \
		srcs/sort_ten.c \
		srcs/chunk_sort.c \
		srcs/quick_sort.c 

OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(FLAGS) $(HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

norm:
	norminette -R checkforbiddensourceheader $(SRCS)
	norminette -R checkdefine includes/push_swap.h

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf push_swap.dSYM

re:	fclean all

bonus: all

.PHONY:	bonus clean fclean all re
