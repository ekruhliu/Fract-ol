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
		@# @ gcc $(FLAGS) $(HEADER) $(SRCS)
		@# @ gcc -o $(NAME) $(OBJ) libft/libft.a $(MLX)
		@ gcc -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -O3 $(SRCS) libft/libft.a
		@ echo "${WHITE}LIST OF FRACTOLS${NORMAL}"
		@ echo "1: Mandelbrot"
		@ echo "2: Julia"
		@ echo "3: Burnship"
		@ echo "4: Mandelbrot 4th Order"
		@ echo "5: Celtic Mandelbrot"
		@ echo "6: Verticat Mandelbrot 5th Order"
		@ echo "7: Burnship 5th Order"
		@ echo "8: Cubic Burnship"
		@ echo "9: Imag Quasi Perpendicular"
		@ echo "10: Celtic 5th Order Mbal"
		@ echo "${WHITE}Select from 1 to 4${NORMAL}"

clean:
		@ /bin/rm -f $(OBJ) ./fract.h.gch
		@ make -C libft/ clean

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean

re: fclean all
