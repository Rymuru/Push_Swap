
SRCS	=	\
			algorithm.c			\
			operations.c		\
			opbis.c				\
			push_swap.c			\
			resize.c			\
			to_radix.c			\
			utils.c


SRCSD	= srcs/

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc -c -o
LINKER	= gcc -o
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g

${NAME}:	${OBJS}
			${LINKER} ${NAME} ${OBJS}

all:		${NAME}

${OBJSD}%.o:    ${SRCSD}%.c
	${CC} $@ $^ ${CFLAGS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re