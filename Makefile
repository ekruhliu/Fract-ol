# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 12:27:45 by ekruhliu          #+#    #+#              #
#    Updated: 2018/03/12 12:27:47 by ekruhliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -c -Wall -Wextra -Werror -O3

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = fract.h

SRCS = lines_parts.c move.c pth.c magik.c zoom.c mouse.c depth.c usage.c fractals.c fractals_part_1.c \
klavochka.c depth_parts.c change_colors.c make_complex_X_Y_parts.c main.c

OBJ = lines_parts.o move.o pth.o magik.o zoom.o mouse.o depth.o usage.o fractals.o fractals_part_1.o \
klavochka.o depth_parts.o change_colors.o make_complex_X_Y_parts.o main.o

all: $(NAME)

$(NAME):
		@ make -C libft/
		@ gcc $(FLAGS) $(HEADER) $(SRCS)
		@ gcc -o $(NAME) $(OBJ) libft/libft.a $(MLX)

clean:
		@ /bin/rm -f $(OBJ) ./fract.h.gch
		@ make -C libft/ clean

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean

re: fclean all
