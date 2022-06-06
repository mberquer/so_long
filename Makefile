# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 11:26:16 by mberquer          #+#    #+#              #
#    Updated: 2022/05/16 17:09:21 by mberquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -f
NAME	= so_long
SRCS	= $(addprefix src/, so_check.c so_event.c so_free.c so_image.c \
			so_long.c so_move.c so_parse.c)
OBJS	= ${SRCS:.c=.o}
DEPS	= ${SRCS:.c=.d}
MLXH	= -I /usr/local/include
MLXS	= -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
INCDIR	= $(addprefix -I, libmlx /usr/include includes libft)
LIBDIR	= $(addprefix -L, libmlx /usr/lib libft)
CFLAGS	= -Wall -Wextra -Werror -g
LIBINC	= -lXext -lX11 -lm -lz -lmlx -lft
LIBMLX	= mlx_linux/libmlx.a
LIBFT	= libft/libft.a

%.o:%.c
	${CC} ${CFLAGS} -MMD -c $< -o $@ ${INCDIR}

${NAME}:${OBJS}
	make -s -C mlx_linux
	make -s -C libft
	make -s -C ft_printf
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

-include ${DEPS}

.PHONY: all clean fclean re