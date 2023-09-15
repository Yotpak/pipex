NAME = pipex
CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -rf
SRCS = pipex.c\
		pipex_utils.c\

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
		$(RM) $(NAME)
		make clean -C

re : fclean all
