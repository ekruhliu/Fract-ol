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

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <pthread.h>

# define VISOTA 800
# define WIRINA 800
# define PIXELS 640000
# define RET_DEPTH all->ret_depth
# define DEPTH all->depth
# define R key == 83 || key == 18
# define G key == 84 || key == 19
# define B key == 85 || key == 20
# define RSTRT "Restart: R"
# define ON_CLR "On Colors: Red: 1 |***| Green: 2 |***| Blue: 3 |***| Psy: S"
# define DPTH "Depth plus: '+' |***| Depth minus: '-'"
# define CLR "Change color: PgUp || PgDn"
# define CH_FRCT "Change Fracals: < || >"
# define UP_DWN "Move UP: ArrowUp || W |***| Move DOWN: ArrowDown || X"
# define LFT_RGHT "Move LEFT: ArrowLeft || A |***| Move RIGHT: ArrorRight || D"
# define DGNL_MV_UP "Move UpLeft: Q |***| Move UpRight: E"
# define DGNL_MV_DN "Move DownLeft: Z |***| Move DownRight: C"
# define MAX_REAL all->complex->max_real
# define MIN_REAL all->complex->min_real
# define MAX_FALSE all->complex->max_false
# define MIN_FALSE all->complex->min_false
# define DATA_ADDR_1 all->img->image, &all->img->bits
# define DATA_ADDR_2 &all->img->size_line, &all->img->end
# define STANDART_INPUT 0
# define SQR_X_X sqr_r_x * sqr_r_x
# define SQR_Y_Y sqr_f_y * sqr_f_y
# define SQR_X_Y sqr_r_x * sqr_f_y
# define DIFF_X_Y sqr_r_x - sqr_f_y
# define COMPLEX_Y all->complex_2[i].complex_y
# define COMPLEX_X all->complex_2[i].complex_x
# define SUM_SQR (SQR_X_Y) + (SQR_Y_Y)
# define PRT_OF_EQU (SQR_X_X) - 10 * (SQR_X_Y)
# define X all->complex_2[i].x
# define Y all->complex_2[i].y

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
	double		complex_x;
	double		complex_y;
	int			red;
	int			green;
	int			blue;
}				t_complex_2;

typedef struct	s_img
{
	int			bits;
	int			size_line;
	int			end;
	char		*line;
	void		*image;
}				t_img;

typedef	struct	s_all
{
	void		*mlx;
	void		*win;
	char		*print_depth;
	int			depth;
	int			color;
	int			ret_depth;
	int			w_t_f;
	int			help;
	int			color_on;
	double		real_julia;
	double		false_julia;
	double		complex_mouse_x;
	double		complex_mouse_y;
	t_complex	*complex;
	t_complex_2	*complex_2;
	t_img		*img;
}				t_all;

int				fractal_mandelbrot(t_all *all, int i);
int				fractal_burnship(t_all *all, int i);
int				fractal_julia(t_all *all, int i);
int				klavochka(int key, t_all *all);
int				fractals(t_all *all, int i);
int				mouse(int x, int y, t_all *all);
int				exit_x(void);
void			magik(t_all *all);
void			usage(void);
void			error(void);
void			make_complex_r_f(t_all *all);
void			depth_plus(t_all *all);
void			depth_minus(t_all *all);
void			make_complex_x_y(t_all *all, int i);
int				zoom(int key, int x, int y, t_all *all);
void			magik(t_all *all);
void			potoki(t_all *all);
void			*depth_part_1(void *op);
void			*depth_part_2(void *op);
void			*depth_part_3(void *op);
void			*depth_part_4(void *op);
void			*lines_part_1(void *op);
void			*lines_part_2(void *op);
void			*lines_part_3(void *op);
void			*lines_part_4(void *op);
void			save_color(t_all *all, int color, int i);
void			create_image(t_all *all);
void			create_lines(t_all *all, int i);
int				fractal_mandelbrot_4th(t_all *all, int i);
int				fractal_celtic_mandelbrot(t_all *all, int i);
int				fractal_verticat_mandelbrot_5th(t_all *all, int i);
int				fractal_burnship_5th(t_all *all, int i);
int				fractal_cubic_burnship(t_all *all, int i);
int				fractal_imag_quasi_perpendicular(t_all *all, int i);
int				fractal_celtic_5th_mbal(t_all *all, int i);
void			potoki(t_all *all);
void			potoki_2(t_all *all);
void			potoki_3(t_all *all);
void			*make_comlpex_x_y_part_1(void *op);
void			*make_comlpex_x_y_part_2(void *op);
void			*make_comlpex_x_y_part_3(void *op);
void			*make_comlpex_x_y_part_4(void *op);
void			color_plus(t_all *all);
void			color_minus(t_all *all);
void			color_on(t_all *all);
void			color_off(t_all *all);
void			move_up(t_all *all);
void			move_down(t_all *all);
void			help(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);
void			dgnl_move_u_l(t_all *all);
void			dgnl_move_u_r(t_all *all);
void			dgnl_move_d_l(t_all *all);
void			dgnl_move_d_r(t_all *all);
void			open_window(t_all *all);
void			make_coordinate(t_all *all);
void			two_fractals(char *argv_1, char *argv_2);
void			three_fractals(char *argv_1, char *argv_2, char *argv_3);
void			four_fractals(char *ar_1, char *ar_2, char *ar_3, char *ar_4);

#endif
