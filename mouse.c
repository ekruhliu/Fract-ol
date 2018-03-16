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

#include "fract.h"

static void	false_julia(t_all *all, int y)
{
	double	range_Y;

	range_Y = 0;
	range_Y = (MAX_FALSE - MIN_FALSE) / VISOTA;
	all->false_julia = y * range_Y + MIN_FALSE;
}

static void	true_julia(t_all *all, int x)
{
	double	range_X;

	range_X = 0;
	range_X = (MAX_REAL - MIN_REAL) / WIRINA;
	all->true_julia = x * range_X + MIN_REAL;
}


int	mouse(int x, int y, t_all *all)
{
	if (all->w_t_f == 2)
	{
		true_julia(all, x);
		false_julia(all, y);
		magik(all);
	}
	return(0);
}
