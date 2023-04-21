NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
# MLX_FLAG = -framework OpenGL -framework AppKit -Lmlx -lmlx
HEAD = -Imlx

SRCS = 	check_error.c \
		qs.c \
		ft_split.c \
		get_input.c \
		oprt_push.c \
		oprt_rerotate.c \
		oprt_rotate.c \
		oprt_swap.c \
		sort_three.c \
		push_swap.c \
		utils_lst.c \
		utils.c \
		sort_five.c \
		sort_100.c \
		# sort_hundred.c \

OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(FLAGS) $(HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

norm:
	norminette -R checkforbiddensourceheader $(SRCS)
	# norminette -R checkdefine so_long.h get_next_line/get_next_line.h

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf push_swap.dSYM

re:	fclean all

bonus: all

.PHONY:	bonus clean fclean all re
