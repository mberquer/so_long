# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 11:26:16 by mberquer          #+#    #+#              #
#    Updated: 2022/06/14 13:22:59 by mberquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/so_long.c \
		src/so_check.c \
		src/so_event.c \
		src/so_free.c \
		src/so_image.c \
		src/so_move.c \
		src/so_parse.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		ft_printf/ft_print_char.c \
		ft_printf/ft_print_hexa.c \
		ft_printf/ft_print_nbr.c \
		ft_printf/ft_print_ptr.c \
		ft_printf/ft_print_str.c \
		ft_printf/ft_print_unsigned.c \
		ft_printf/ft_printf.c \
		
OBJ = $(SRCS:%.c=%.o)

CC = cc

MLX = mlx_linux/libmlx_Linux.a 

$(NAME): $(OBJ) $(MLX)
	$(CC) $(OBJ) -g3 -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) #-fsanitize=address

%.o: %.c
	$(CC) -g3 -DBUFFER_SIZE=1 -Wall -Wextra -Werror -I/usr/include -Imlx -O0 -c $< -o $@

$(MLX):
	make -C ./mlx_linux


clean: 
	rm -rf $(OBJ)

test: $(NAME)
	valgrind ./so_long maps/missingC.ber
	valgrind ./so_long maps/missingE.ber
	valgrind ./so_long maps/missingP.ber
	valgrind ./so_long maps/DoubleP.ber
	valgrind ./so_long maps/NotClosed.ber
	valgrind ./so_long maps/NotRectangle.ber
	valgrind ./so_long maps/NotSymb.ber

fclean: clean
	rm -rf $(NAME)

all: $(NAME) 
	
re: fclean
	make all
	
.PHONY: clean fclean all re 