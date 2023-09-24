NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra 
SRCS = pipex.c pipex_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
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