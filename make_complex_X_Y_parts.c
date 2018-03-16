/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_complex_X_Y_parts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:31:27 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/16 09:31:28 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*make_comlpex_X_Y_part_1(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 0;
	while (i < 160000)
	{
		make_complex_X_Y(all, i);
		i++;
	}
	pthread_exit(0);
}

void	*make_comlpex_X_Y_part_2(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 160000;
	while (i < 320000)
	{
		make_complex_X_Y(all, i);
		i++;
	}
	pthread_exit(0);
}

void	*make_comlpex_X_Y_part_3(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 320000;
	while (i < 480000)
	{
		make_complex_X_Y(all, i);
		i++;
	}
	pthread_exit(0);
}

void	*make_comlpex_X_Y_part_4(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 480000;
	while (i < 640000)
	{
		make_complex_X_Y(all, i);
		i++;
	}
	pthread_exit(0);
}

void	make_complex_X_Y(t_all *all, int i)
{
	double	range_X;
	double	range_Y;

	range_X = 0;
	range_Y = 0;
	range_Y = (MAX_FALSE - MIN_FALSE) / VISOTA;
	all->complex_2[i].complex_Y = all->complex_2[i].y * range_Y + MIN_FALSE;
	range_X = (MAX_REAL - MIN_REAL) / WIRINA;
	all->complex_2[i].complex_X = all->complex_2[i].x * range_X + MIN_REAL;
}
