/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magik.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:08:12 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 17:08:13 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*depth_part_1(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 0;
	all->ret_depth = 0;
	while (i < 250000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	return (0);
}

void	*depth_part_2(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 250000;
	all->ret_depth = 0;
	while (i < 500000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	return (0);
}

void	*depth_part_3(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 500000;
	all->ret_depth = 0;
	while (i < 750000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	return (0);
}

void	*depth_part_4(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 750000;
	all->ret_depth = 0;
	while (i < 1000000)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	return (0);
}

void	*lines_part_1(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 0;
	while (i < 250000)
	{
		create_lines(all, i);
		i++;
	}
	return (0);
}

void	*lines_part_2(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 250000;
	while (i < 500000)
	{
		create_lines(all, i);
		i++;
	}
	return (0);
}

void	*lines_part_3(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 500000;
	while (i < 750000)
	{
		create_lines(all, i);
		i++;
	}	
	return (0);
}

void	*lines_part_4(void *op)
{
	int i;
	t_all	*all;

	all = (t_all*)op;
	i = 750000;
	while (i < 1000000)
	{
		create_lines(all, i);
		i++;
	}
	return (0);
}

void	magik(t_all *all)
{
	int i;

	i = 0;
	depth_part_1(all);
	depth_part_2(all);
	depth_part_3(all);
	depth_part_4(all);
	create_image(all);
	lines_part_1(all);
	lines_part_2(all);
	lines_part_3(all);
	lines_part_4(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img->image, 0, 0);
	free(all->img);
}
