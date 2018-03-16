/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:19:25 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/12 12:19:26 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "./libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <pthread.h>

# define VISOTA 800
# define WIRINA 800
# define PIXELS 640000
# define RSTRT "Restart: R"
# define ON_CLR "On Color: C"
# define DPTH "Depth plus: '+' |***| Depth minus: '-'"
# define CLR "Change color: PgUp || PgDn"
# define UP_DWN "Move UP: ArrowUp |***| Move DOWN: ArrowDown"
# define LFT_RGHT "Move LEFT: ArrowLeft |***| Move RIGHT: ArrorRight"
# define MAX_REAL all->complex->max_real
# define MIN_REAL all->complex->min_real
# define MAX_FALSE all->complex->max_false
# define MIN_FALSE all->complex->min_false
# define DATA_ADDR_1 all->img->image, &all->img->bits
# define DATA_ADDR_2 &all->img->size_line, &all->img->end
# define STANDART_INPUT 0

typedef	struct	s_complex
{
	double		max_real;
	double		min_real;
	double		max_false;
	double		min_false;
}				t_complex;

typedef	struct	s_complex_2
{
	double		x;
	double		y;
	double		complex_X;
	double		complex_Y;
	int			red;
	int			green;
	int			blue;
}				t_complex_2;

typedef struct	s_img
{
	int		bits;
	int		size_line;
	int		end;
	char	*line;
	void	*image;
}				t_img;

typedef	struct	s_all
{
	void		*mlx;
	void		*win;
	int			depth;
	int			color;
	int 		ret_depth;
	int			w_t_f;
	int			help;
	int			color_on;
	double		true_julia;
	double		false_julia;
	double		complex_mouse_X;
	double		complex_mouse_Y;
	// double		tmp_true_julia;
	// double		tmp_false_julia;
	// double		tmp_complex_mouse_X;
	// double		tmp_complex_mouse_Y;
	t_complex	*complex;
	t_complex_2	*complex_2;
	t_img		*img;
	// t_complex_2	*tmp;
}				t_all;

int		fractal_mandelbrot(t_all *all, int i);
int		fractal_burnship(t_all *all, int i);
int		fractal_julia(t_all *all, int i);
int		klavochka(int key, t_all *all);
int		fractals(t_all *all, int i);
int		mouse(int x, int y, t_all *all);
int		exit_x(void);
void	magik(t_all *all);
void	usage(void);
void	depth_plus(t_all *all);
void	depth_minus(t_all *all);
void	make_complex_X_Y(t_all *all, int i);
int		zoom(int key, int x, int y, t_all *all);
void	magik(t_all *all);
void	potoki(t_all *all);
void	*depth_part_1(void *op);
void	*depth_part_2(void *op);
void	*depth_part_3(void *op);
void	*depth_part_4(void *op);
void	*lines_part_1(void *op);
void	*lines_part_2(void *op);
void	*lines_part_3(void *op);
void	*lines_part_4(void *op);
void	ft_color_fill(t_all *all, int color, int i);
void	create_image(t_all *all);
void	create_lines(t_all *all, int i);
int		fractal_test(t_all *all, int i);
void	potoki(t_all *all);
void	potoki_2(t_all *all);
void	potoki_3(t_all *all);
void	*make_comlpex_X_Y_part_1(void *op);
void	*make_comlpex_X_Y_part_2(void *op);
void	*make_comlpex_X_Y_part_3(void *op);
void	*make_comlpex_X_Y_part_4(void *op);
void	color_plus(t_all *all);
void	color_minus(t_all *all);
void	move_up(t_all *all);
void	move_down(t_all *all);
void	help(t_all *all);
// void	move_left(t_all *all);
// void	move_right(t_all *all);

#endif
