NAME = pipex
NAME_B = pipex_bonus
CC = gcc
CFLAGS = -Wall -Wextra 
SRCS = pipex.c pipex_utils.c
SRCS_B = pipex_bonus.c pipex_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

.c.o:
	@$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) libft/libft.a

$(NAME_B): $(OBJS_B)
	@make -C libft
	@$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME) libft/libft.a

clean:
	@make -C libft clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_B)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(NAME_B)	

re: fclean all

bonus: $(NAME_B)


.PHONY: all clean fclean re