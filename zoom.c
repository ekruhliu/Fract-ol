/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:04:33 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 16:04:34 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	complex_mouse_Y(t_all *all, int y)
{
	double	range_Y;

	range_Y = 0;
	range_Y = (all->complex->max_false - all->complex->min_false) / VISOTA;
	all->complex_mouse_Y = y * range_Y + all->complex->min_false;
}

static void	complex_mouse_X(t_all *all, int x)
{
	double	range_X;

	range_X = 0;
	range_X = (all->complex->max_real - all->complex->min_real) / WIRINA;
	all->complex_mouse_X = x * range_X + all->complex->min_real;
}

static void	zoom_plus(t_all *all, int x, int y)
{
	int i;

	i = 0;
	complex_mouse_X(all, x);
	complex_mouse_Y(all, y);
	all->complex->max_real = all->complex->max_real * 1.1 + all->complex_mouse_X * (1 - 1.1);
	all->complex->min_real = all->complex->min_real * 1.1 + all->complex_mouse_X * (1 - 1.1);
	all->complex->max_false = all->complex->max_false * 1.1 + all->complex_mouse_Y * (1 - 1.1);
	all->complex->min_false = all->complex->min_false * 1.1 + all->complex_mouse_Y * (1 - 1.1);
	while (i < PIXELS)
	{
		make_complex_X_Y(all, i);
		i++;
	}
	magik(all);
}

static void	zoom_minus(t_all *all, int x, int y)
{
	int i;

	i = 0;
	complex_mouse_X(all, x);
	complex_mouse_Y(all, y);
	all->complex->max_real = all->complex->max_real * 0.9 + all->complex_mouse_X * (1 - 0.9);
	all->complex->min_real = all->complex->min_real * 0.9 + all->complex_mouse_X * (1 - 0.9);
	all->complex->max_false = all->complex->max_false * 0.9 + all->complex_mouse_Y * (1 - 0.9);
	all->complex->min_false = all->complex->min_false * 0.9 + all->complex_mouse_Y * (1 - 0.9);
	while (i < PIXELS)
	{
		make_complex_X_Y(all, i);
		i++;
	}
	magik(all);
}

int		zoom(int key, int x, int y, t_all *all)
{
	if (key == 5 || key == 4)
		(key == 5 ? zoom_plus(all, x, y) : zoom_minus(all, x, y));
	return (0);
}