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

#include "fract.h"

void	*depth_part_1(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 0;
	while (i < 160000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth)
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	pthread_exit(0);
}

void	*depth_part_2(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 160000;
	all->ret_depth = all->ret_depth;
	while (i < 320000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	pthread_exit(0);
}

void	*depth_part_3(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 320000;
	all->ret_depth = all->ret_depth;
	while (i < 480000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	pthread_exit(0);
}

void	*depth_part_4(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 480000;
	all->ret_depth = all->ret_depth;
	while (i < 640000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	pthread_exit(0);
}
