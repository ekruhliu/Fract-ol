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

# define VISOTA 1100
# define WIRINA 1100
# define PIXELS 1210000
# define MAX_REAL
# define MIN_REAL
# define MAX_FALSE
# define MIN_FALSE
# define DATA_ADDR_1 all->img->image, &all->img->bits
# define DATA_ADDR_2 &all->img->size_line, &all->img->end

typedef	struct	s_complex
{
	double			max_real;
	double			min_real;
	double			max_false;
	double			min_false;
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
	t_complex	*complex;
	t_complex_2	*complex_2;
	t_img		*img;
}				t_all;

int		fractal_mandelbrot(t_all *all, int i);
int		fractal_burnship(t_all *all, int i);
int		klavochka(int key, t_all *all);
int		exit_x(void);

#endif