NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c pipex_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	@$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) libft/libft.a

clean:
	@make -C libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re