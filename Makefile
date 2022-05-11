CC		= cc
RM		= rm -f
NAME	= so_long
SRCS	=
OBJS	= ${SRCS:.c=.o}
CFLAGS	= -Wall -Wextra -Werror -g


%.o:%.c
	${CC} ${CFLAGS} -MMD -c $< -o $@ ${INCDIR}

${NAME}:${OBJS}
	make -s -C libmlx
	make -s -C libft
	${CC} ${CFLAGS} ${OBJS} ${LIBDIR} ${LIBINC} -o ${NAME}

all:${NAME}

clean:
	make -s -C libft clean
	${RM} ${OBJS} ${DEPS}

fclean:clean
	make -s -C libmlx clean
	make -s -C libft fclean
	${RM} ${NAME}

re:fclean all

.PHONY: all clean fclean re