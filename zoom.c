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
	range_Y = (MAX_FALSE - MIN_FALSE) / VISOTA;
	all->complex_mouse_Y = y * range_Y + MIN_FALSE;
}

static void	complex_mouse_X(t_all *all, int x)
{
	double	range_X;

	range_X = 0;
	range_X = (MAX_REAL - MIN_REAL) / WIRINA;
	all->complex_mouse_X = x * range_X + MIN_REAL;
}

static void	zoom_plus(t_all *all, int x, int y)
{
	int i;

	i = 0;
	complex_mouse_X(all, x);
	complex_mouse_Y(all, y);
	MAX_REAL = MAX_REAL * 1.1 + all->complex_mouse_X * (1 - 1.1);
	MIN_REAL = MIN_REAL * 1.1 + all->complex_mouse_X * (1 - 1.1);
	MAX_FALSE = MAX_FALSE * 1.1 + all->complex_mouse_Y * (1 - 1.1);
	MIN_FALSE = MIN_FALSE * 1.1 + all->complex_mouse_Y * (1 - 1.1);
	potoki_3(all);
	magik(all);
}

static void	zoom_minus(t_all *all, int x, int y)
{
	int i;

	i = 0;
	complex_mouse_X(all, x);
	complex_mouse_Y(all, y);
	MAX_REAL = MAX_REAL * 0.9 + all->complex_mouse_X * (1 - 0.9);
	MIN_REAL = MIN_REAL * 0.9 + all->complex_mouse_X * (1 - 0.9);
	MAX_FALSE = MAX_FALSE * 0.9 + all->complex_mouse_Y * (1 - 0.9);
	MIN_FALSE = MIN_FALSE * 0.9 + all->complex_mouse_Y * (1 - 0.9);
	potoki_3(all);
	magik(all);
}

int		zoom(int key, int x, int y, t_all *all)
{
	if (key == 5 || key == 4)
		(key == 5 ? zoom_plus(all, x, y) : zoom_minus(all, x, y));
	return (0);
}