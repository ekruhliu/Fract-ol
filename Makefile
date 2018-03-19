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

HEADER = ./includes/fract.h

LIBFT = ./libft/libft.a

SRCS = ./srcs/lines_parts.c ./srcs/move.c ./srcs/magik.c ./srcs/zoom.c ./srcs/mouse.c ./srcs/depth.c ./srcs/usage_and_error.c ./srcs/fractals.c \
./srcs/fractals_part_1.c ./srcs/klavochka.c ./srcs/fractals_part_2.c ./srcs/depth_parts.c ./srcs/change_colors.c ./srcs/make_complex_X_Y_parts.c \
./srcs/poroki_1.c ./srcs/poroki_2.c ./srcs/poroki_3.c ./srcs/diagonal_moves.c ./srcs/help.c ./srcs/exit_x.c ./srcs/create_image.c \
./srcs/make_complex_r_f.c ./srcs/make_coordinate.c ./srcs/open_window.c ./srcs/save_color.c ./srcs/two_fractals.c ./srcs/three_fractals.c \
./srcs/four_fractals.c ./srcs/main.c

OBJ = lines_parts.o move.o magik.o zoom.o mouse.o depth.o usage_and_error.o fractals.o fractals_part_1.o \
klavochka.o fractals_part_2.o depth_parts.o change_colors.o make_complex_X_Y_parts.o poroki_1.o \
poroki_2.o poroki_3.o diagonal_moves.o help.o exit_x.o create_image.o make_complex_r_f.o make_coordinate.o\
open_window.o save_color.o two_fractals.o three_fractals.o four_fractals.o main.o

all: $(NAME)

$(NAME):
		@ make -C libft/
		@ @ gcc $(FLAGS) $(HEADER) $(SRCS)
		@ @ gcc -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
		@ sh ./script/inf.sh

clean:
		@ /bin/rm -f $(OBJ) ./includes/fract.h.gch
		@ make -C libft/ clean

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean

re: fclean all
