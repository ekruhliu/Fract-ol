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

# define VISOTA 1000
# define WIRINA 1000
# define PIXELS 1000000
# define MAX_REAL
# define MIN_REAL
# define MAX_FALSE
# define MIN_FALSE
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
	double		true_julia;
	double		false_julia;
	double		complex_mouse_X;
	double		complex_mouse_Y;
	t_complex	*complex;
	t_complex_2	*complex_2;
	t_img		*img;
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
// void	move_up(t_all *all);
// void	move_down(t_all *all);
// void	move_left(t_all *all);
// void	move_right(t_all *all);

#endif
