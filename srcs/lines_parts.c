/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:14:48 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/16 09:14:49 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void		*lines_part_1(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 0;
	while (i < 160000)
	{
		create_lines(all, i);
		i++;
	}
	pthread_exit(0);
}

void		*lines_part_2(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 160000;
	while (i < 320000)
	{
		create_lines(all, i);
		i++;
	}
	pthread_exit(0);
}

void		*lines_part_3(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 320000;
	while (i < 480000)
	{
		create_lines(all, i);
		i++;
	}
	pthread_exit(0);
}

void		*lines_part_4(void *op)
{
	int		i;
	t_all	*all;

	all = (t_all*)op;
	i = 480000;
	while (i < 640000)
	{
		create_lines(all, i);
		i++;
	}
	pthread_exit(0);
}

void		create_lines(t_all *all, int i)
{
	int		x;

	if ((int)Y >= 0 && (int)X >= 0)
	{
		if ((int)Y < VISOTA && (int)X < WIRINA)
		{
			x = (int)Y * all->img->size_line + (int)X * 4;
			if (x < VISOTA * WIRINA * 4)
			{
				all->img->line[x] = all->complex_2[i].blue;
				all->img->line[x + 1] = all->complex_2[i].green;
				all->img->line[x + 2] = all->complex_2[i].red;
			}
		}
	}
}
