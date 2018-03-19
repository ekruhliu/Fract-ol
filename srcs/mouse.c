/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:52:55 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 14:52:57 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

static	void	false_julia(t_all *all, int y)
{
	double	range_y;

	range_y = (MAX_FALSE - MIN_FALSE) / VISOTA;
	all->false_julia = y * range_y + MIN_FALSE;
}

static	void	real_julia(t_all *all, int x)
{
	double	range_x;

	range_x = (MAX_REAL - MIN_REAL) / WIRINA;
	all->real_julia = x * range_x + MIN_REAL;
}

int				mouse(int x, int y, t_all *all)
{
	if (all->w_t_f == 2)
	{
		real_julia(all, x);
		false_julia(all, y);
		magik(all);
	}
	return (0);
}
