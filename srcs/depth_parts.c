/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:14:59 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/16 09:15:00 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void		*depth_part_1(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 0;
	while (i < 160000)
	{
		RET_DEPTH = fractals(all, i);
		if (RET_DEPTH < DEPTH)
			save_color(all, (((RET_DEPTH + 1) % (i + 1)) * all->color), i);
		else
			save_color(all, 0, i);
		i++;
	}
	pthread_exit(0);
}

void		*depth_part_2(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 160000;
	RET_DEPTH = RET_DEPTH;
	while (i < 320000)
	{
		RET_DEPTH = fractals(all, i);
		if (RET_DEPTH < DEPTH)
			save_color(all, (((RET_DEPTH + 1) % (i + 1)) * all->color), i);
		else
			save_color(all, 0, i);
		i++;
	}
	pthread_exit(0);
}

void		*depth_part_3(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 320000;
	RET_DEPTH = RET_DEPTH;
	while (i < 480000)
	{
		RET_DEPTH = fractals(all, i);
		if (RET_DEPTH < DEPTH)
			save_color(all, (((RET_DEPTH + 1) % (i + 1)) * all->color), i);
		else
			save_color(all, 0, i);
		i++;
	}
	pthread_exit(0);
}

void		*depth_part_4(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 480000;
	RET_DEPTH = RET_DEPTH;
	while (i < 640000)
	{
		RET_DEPTH = fractals(all, i);
		if (RET_DEPTH < DEPTH)
			save_color(all, (((RET_DEPTH + 1) % (i + 1)) * all->color), i);
		else
			save_color(all, 0, i);
		i++;
	}
	pthread_exit(0);
}
