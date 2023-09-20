NAME = push_swap

SRCS = src/main.c src/errors.c src/aux_functions.c src/index_function.c src/list_functions.c\
		src/main_moves.c src/moves.c src/moves2.c src/sort.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iinc/
LIBFT = libft/libft.a


all: $(NAME) $(BONUS)

.PHONY: all, fclean, re

$(NAME): $(OBJS)
		make -C libft/
		cc $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	rm -f $(OBJS) $(B_OBJS)
	make fclean -C libft/
	
fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
