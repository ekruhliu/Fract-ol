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

#include "../includes/fract.h"

static	void	complex_mouse_y(t_all *all, int y)
{
	double	range_y;

	range_y = 0;
	range_y = (MAX_FALSE - MIN_FALSE) / VISOTA;
	all->complex_mouse_y = y * range_y + MIN_FALSE;
}

static	void	complex_mouse_x(t_all *all, int x)
{
	double	range_x;

	range_x = 0;
	range_x = (MAX_REAL - MIN_REAL) / WIRINA;
	all->complex_mouse_x = x * range_x + MIN_REAL;
}

static	void	zoom_plus(t_all *all, int x, int y)
{
	int i;

	i = 0;
	complex_mouse_x(all, x);
	complex_mouse_y(all, y);
	MAX_REAL = MAX_REAL * 1.1 + all->complex_mouse_x * (1 - 1.1);
	MIN_REAL = MIN_REAL * 1.1 + all->complex_mouse_x * (1 - 1.1);
	MAX_FALSE = MAX_FALSE * 1.1 + all->complex_mouse_y * (1 - 1.1);
	MIN_FALSE = MIN_FALSE * 1.1 + all->complex_mouse_y * (1 - 1.1);
	potoki_3(all);
	magik(all);
}

static	void	zoom_minus(t_all *all, int x, int y)
{
	int i;

	i = 0;
	complex_mouse_x(all, x);
	complex_mouse_y(all, y);
	MAX_REAL = MAX_REAL * 0.9 + all->complex_mouse_x * (1 - 0.9);
	MIN_REAL = MIN_REAL * 0.9 + all->complex_mouse_x * (1 - 0.9);
	MAX_FALSE = MAX_FALSE * 0.9 + all->complex_mouse_y * (1 - 0.9);
	MIN_FALSE = MIN_FALSE * 0.9 + all->complex_mouse_y * (1 - 0.9);
	potoki_3(all);
	magik(all);
}

int				zoom(int key, int x, int y, t_all *all)
{
	if (key == 5 || key == 4)
		(key == 5 ? zoom_plus(all, x, y) : zoom_minus(all, x, y));
	return (0);
}
