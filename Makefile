
SRCS	=	\
			push_swap.c			\
			utils.c


SRCSD	= srcs/

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc -c -o
LINKER	= gcc -o
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

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