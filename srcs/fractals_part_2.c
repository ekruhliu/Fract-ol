/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_part_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:20:21 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 10:20:22 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

int		fractal_verticat_mandelbrot_5th(t_all *all, int i)
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
		f_y = -f_y * (5 * PRT_OF_EQU + (SQR_Y_Y)) + COMPLEX_Y;
		r_x = r_x * (PRT_OF_EQU + 5 * (SQR_Y_Y)) + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_burnship_5th(t_all *all, int i)
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
		f_y = fabs(f_y) * (5 * PRT_OF_EQU + (SQR_Y_Y)) + COMPLEX_Y;
		r_x = fabs(r_x) * (PRT_OF_EQU + 5 * (SQR_Y_Y)) + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_cubic_burnship(t_all *all, int i)
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
		f_y = ((sqr_r_x * 3.0) - sqr_f_y) * fabs(f_y) + COMPLEX_Y;
		r_x = ((sqr_r_x - (sqr_f_y * 3.0)) * fabs(r_x) + COMPLEX_X);
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_imag_quasi_perpendicular(t_all *all, int i)
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
		f_y = 4 * r_x * fabs(f_y) * fabs(DIFF_X_Y) + COMPLEX_Y;
		r_x = SQR_X_X + SQR_Y_Y - 6 * SQR_X_Y + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_celtic_5th_mbal(t_all *all, int i)
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
		f_y = -f_y * (5 * PRT_OF_EQU + (SQR_Y_Y)) + COMPLEX_Y;
		r_x = fabs(r_x * (PRT_OF_EQU + 5 * (SQR_Y_Y))) + COMPLEX_X;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}
