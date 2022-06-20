
SRCS	=	\
			algorithm.c			\
			operations.c		\
			opbis.c				\
			push_swap.c			\
			resize.c			\
			to_radix.c			\
			quicksort.c			\
			quickutils.c		\
			utils.c


SRCSD	= srcs/

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= cc
LINKER	= cc
RM		= rm -rf

CFLAGS	= -c -Wall -Wextra -Werror

${NAME}:	${OBJS}
			${LINKER} -o ${NAME} ${OBJS}

all:		${NAME}

${OBJSD}%.o:    ${SRCSD}%.c
	${CC} -o $@ $^ ${CFLAGS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re