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
			break ;
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
		//false_Y = 2 * true_X * false_Y + all->false_julia;
		//true_X = tmp + all->true_julia;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			break ;
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
			break ;
		n++;
	}
	return (n);
}

int		fractal_test(t_all *all, int i)
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
			break ;
		n++;
	}
	return (n);
}
