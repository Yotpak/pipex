PROG	= pipex
SRCS 	= pipex.c pipex_utils.c ft_child_parent.c ft_execute.c ft_error.c
OBJS 	= ${SRCS:.c=.o}
CC 		= gcc
CFLAGS = -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@$(CC) ${OBJS} -o ${PROG}

clean:
					@rm -f ${OBJS}

fclean: 	clean
					@rm -f $(NAME)
					@rm -f ${PROG}

re:			fclean all

re_bonus:	fclean bonus


.PHONY: all clean fclean re re_bonus bonus party