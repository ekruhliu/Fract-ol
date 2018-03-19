/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_part_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:37:44 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 13:37:44 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

int		fractal_mandelbrot(t_all *all, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	tmp;

	n = 0;
	f_y = 0;
	r_x = 0;
	while (n < all->depth)
	{
		tmp = (r_x * r_x) - (f_y * f_y);
		f_y = 2 * r_x * f_y + COMPLEX_Y;
		r_x = tmp + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_julia(t_all *all, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	tmp;

	n = 0;
	f_y = COMPLEX_Y;
	r_x = COMPLEX_X;
	while (n < all->depth)
	{
		tmp = (r_x * r_x) - (f_y * f_y);
		f_y = 2 * r_x * f_y + all->real_julia;
		r_x = tmp + all->false_julia;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_burnship(t_all *all, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	tmp;

	n = 0;
	f_y = 0;
	r_x = 0;
	while (n < all->depth)
	{
		tmp = (r_x * r_x) - (f_y * f_y);
		f_y = 2 * fabs(r_x * f_y) + COMPLEX_Y;
		r_x = tmp + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_mandelbrot_4th(t_all *all, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	sqr_r_x;
	double	sqr_f_y;

	n = 0;
	f_y = 0;
	r_x = 0;
	while (n < all->depth)
	{
		sqr_r_x = r_x * r_x;
		sqr_f_y = f_y * f_y;
		f_y = 4 * r_x * f_y * (DIFF_X_Y) + COMPLEX_Y;
		r_x = SQR_X_X + SQR_Y_Y - 6 * SQR_X_Y + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_celtic_mandelbrot(t_all *all, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	tmp;

	n = 0;
	f_y = 0;
	r_x = 0;
	while (n < all->depth)
	{
		tmp = (r_x * r_x) - (f_y * f_y);
		f_y = 2 * r_x * f_y + COMPLEX_Y;
		r_x = fabs(tmp) + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}
