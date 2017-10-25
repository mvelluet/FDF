# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 16:44:56 by mvelluet          #+#    #+#              #
#    Updated: 2017/03/23 23:52:14 by mvelluet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =  main.c \
		ft_read.c \
		ft_malloc.c \
		ft_draw.c \
		ft_utils.c \
		ft_command.c

CFLAGS = -Wall -Werror -Wextra

INCLUDE = fdf.h

OBJ = $(SRCS:.c=.o)

CC = gcc

MINILIB = minilibx_macos/libmlx.a

all: $(NAME) $(INCLUDE)

$(NAME): $(MINILIB) $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(MINILIB) -framework OpenGL -framework Appkit libft/libft.a
	echo "Fdf done" $@

$(MINILIB):
	make -C minilibx_macos

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all