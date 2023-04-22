NAME = push_swap
CNAME = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = -Imlx

UTILS =	srcs/check_error.c \
		srcs/check_sort.c \
		srcs/ft_strncmp.c \
		srcs/ft_atoi.c \
		srcs/ft_split.c \
		srcs/get_input.c \
		srcs/oprt_push.c \
		srcs/oprt_rerotate.c \
		srcs/oprt_rotate.c \
		srcs/oprt_swap.c \
		srcs/set_val.c \
		srcs/utils_lst.c \
		srcs/utils.c \

SRCS = 	srcs/push_swap.c \
		srcs/sort_three.c \
		srcs/sort_two.c \
		srcs/sort_ten.c \
		srcs/chunk_sort.c \
		srcs/quick_sort.c \
		$(UTILS)

CSRCS = srcs/checker.c \
		srcs/run_checker.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		$(UTILS) 	

OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(FLAGS) $(HEAD) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

$(CNAME): $(OBJS)
	$(CC) $(FLAGS) $(CSRCS) -o $(CNAME)

norm:
	norminette -R checkforbiddensourceheader $(SRCS)
	norminette -R checkdefine includes/push_swap.h

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(CNAME)
	@rm -rf push_swap.dSYM

re:	fclean all

all: $(NAME)

bonus: $(CNAME)

.PHONY:	bonus clean fclean all re
