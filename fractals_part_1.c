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

#include "fract.h"

int		fractal_mandelbrot(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	tmp;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		tmp = (true_X * true_X) - (false_Y * false_Y);
		false_Y = 2 * true_X * false_Y + all->complex_2[i].complex_Y;
		true_X = tmp + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_julia(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	tmp;

	n = 0;
	false_Y = all->complex_2[i].complex_Y;
	true_X = all->complex_2[i].complex_X;
	while (n < all->depth)
	{
		tmp = (true_X * true_X) - (false_Y * false_Y);
		false_Y = 2 * true_X * false_Y + all->true_julia;
		true_X = tmp + all->false_julia;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_burnship(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	tmp;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		tmp = (true_X * true_X) - (false_Y * false_Y);
		false_Y = 2 * fabs(true_X * false_Y) + all->complex_2[i].complex_Y;
		true_X = tmp + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_mandelbrot_4th(t_all *all, int i)
{
	int	n;
	double	true_X;
	double	false_Y;
	double	sqr_true_X;
	double	sqr_false_Y;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		sqr_true_X = true_X * true_X;
		sqr_false_Y = false_Y * false_Y;
		false_Y = 4 * true_X * false_Y * (sqr_true_X - sqr_false_Y) + all->complex_2[i].complex_Y;
		true_X = sqr_true_X * sqr_true_X + sqr_false_Y * sqr_false_Y - 6 * sqr_true_X * sqr_false_Y + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_celtic_mandelbrot(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	tmp;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		tmp = (true_X * true_X) - (false_Y * false_Y);
		false_Y = 2 * true_X * false_Y + all->complex_2[i].complex_Y;
		true_X = fabs(tmp) + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_verticat_mandelbrot_5th(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	sqr_true_X;
	double	sqr_false_Y;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		sqr_true_X = true_X * true_X;
		sqr_false_Y = false_Y * false_Y;
		false_Y = -false_Y * (5 * (sqr_true_X * sqr_true_X) - 10 * (sqr_true_X * sqr_false_Y) + (sqr_false_Y * sqr_false_Y)) + all->complex_2[i].complex_Y;
		true_X = true_X * ((sqr_true_X * sqr_true_X) - 10 * (sqr_true_X * sqr_false_Y) + 5 * (sqr_false_Y * sqr_false_Y)) + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_burnship_5th(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	sqr_true_X;
	double	sqr_false_Y;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		sqr_true_X = true_X * true_X;
		sqr_false_Y = false_Y * false_Y;
		false_Y = fabs(false_Y) * (5 * (sqr_true_X * sqr_true_X) - 10 * (sqr_true_X * sqr_false_Y) + (sqr_false_Y * sqr_false_Y)) + all->complex_2[i].complex_Y;
		true_X = fabs(true_X) * ((sqr_true_X * sqr_true_X) - 10 * (sqr_true_X * sqr_false_Y) + 5 * (sqr_false_Y * sqr_false_Y)) + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_cubic_burnship(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	sqr_true_X;
	double	sqr_false_Y;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		sqr_true_X = true_X * true_X;
		sqr_false_Y = false_Y * false_Y;
		false_Y = ((sqr_true_X * 3.0) - sqr_false_Y) * fabs(false_Y) + all->complex_2[i].complex_Y;
		true_X = ((sqr_true_X - (sqr_false_Y * 3.0)) * fabs(true_X) + all->complex_2[i].complex_X);
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_imag_quasi_perpendicular(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	sqr_true_X;
	double	sqr_false_Y;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		sqr_true_X = true_X * true_X;
		sqr_false_Y = false_Y * false_Y;
		false_Y = 4 * true_X * fabs(false_Y) * fabs(sqr_true_X - sqr_false_Y) + all->complex_2[i].complex_Y;
		true_X = sqr_true_X * sqr_true_X + sqr_false_Y * sqr_false_Y - 6 * sqr_true_X * sqr_false_Y + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int		fractal_celtic_5th_mbal(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	sqr_true_X;
	double	sqr_false_Y;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		sqr_true_X = true_X * true_X;
		sqr_false_Y = false_Y * false_Y;
		false_Y = -false_Y * (5 * (sqr_true_X * sqr_true_X) - 10 * (sqr_true_X * sqr_false_Y) + (sqr_false_Y * sqr_false_Y)) + all->complex_2[i].complex_Y;
		true_X = fabs(true_X * ((sqr_true_X * sqr_true_X) - 10 * (sqr_true_X * sqr_false_Y) + 5 * (sqr_false_Y * sqr_false_Y))) + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			return (n);
		n++;
	}
	return (n);
}
