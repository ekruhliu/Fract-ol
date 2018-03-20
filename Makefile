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

HEADER = includes/fract.h

LIBFT = libft/libft.a

SRCS = ./srcs/lines_parts.c ./srcs/move.c ./srcs/magik.c ./srcs/zoom.c ./srcs/mouse.c ./srcs/depth.c ./srcs/usage_and_error.c ./srcs/fractals.c \
./srcs/fractals_part_1.c ./srcs/klavochka.c ./srcs/fractals_part_2.c ./srcs/depth_parts.c ./srcs/change_colors.c ./srcs/make_complex_x_y_parts.c \
./srcs/poroki_1.c ./srcs/poroki_2.c ./srcs/poroki_3.c ./srcs/diagonal_moves.c ./srcs/help.c ./srcs/exit_x.c ./srcs/create_image.c \
./srcs/make_complex_r_f.c ./srcs/make_coordinate.c ./srcs/open_window.c ./srcs/save_color.c ./srcs/two_fractals.c ./srcs/three_fractals.c \
./srcs/four_fractals.c ./srcs/main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ make -C libft/
		@ gcc -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
		@ afplay ./script_and_music/1.mp3
		@ sh ./script_and_music/inf.sh

%.o: %.c $(HEADER)
	@ gcc $(FLAGS) -o  $@ $<

clean:
		@ /bin/rm -f $(OBJ) ./includes/fract.h.gch
		@ make -C libft/ clean
		@ echo "\033[1m\033[31mAll the object files have been deleted.\033[0m"

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean
		@ echo "\033[1m\033[31m$(NAME) has been deleted.\033[0m"

re: fclean all
