/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_complex_x_y_parts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:31:27 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/16 09:31:28 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void		*make_comlpex_x_y_part_1(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 0;
	while (i < 160000)
	{
		make_complex_x_y(all, i);
		i++;
	}
	pthread_exit(0);
}

void		*make_comlpex_x_y_part_2(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 160000;
	while (i < 320000)
	{
		make_complex_x_y(all, i);
		i++;
	}
	pthread_exit(0);
}

void		*make_comlpex_x_y_part_3(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 320000;
	while (i < 480000)
	{
		make_complex_x_y(all, i);
		i++;
	}
	pthread_exit(0);
}

void		*make_comlpex_x_y_part_4(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 480000;
	while (i < 640000)
	{
		make_complex_x_y(all, i);
		i++;
	}
	pthread_exit(0);
}

void		make_complex_x_y(t_all *all, int i)
{
	double	range_x;
	double	range_y;

	range_x = 0;
	range_y = 0;
	range_y = (MAX_FALSE - MIN_FALSE) / VISOTA;
	COMPLEX_Y = Y * range_y + MIN_FALSE;
	range_x = (MAX_REAL - MIN_REAL) / WIRINA;
	COMPLEX_X = X * range_x + MIN_REAL;
}
