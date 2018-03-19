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

#include "../includes/fract.h"

void	magik(t_all *all)
{
	potoki(all);
	create_image(all);
	potoki_2(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img->image, 0, 0);
	all->print_depth = ft_itoa(all->depth);
	mlx_string_put(all->mlx, all->win, 755, 10, 0xFF0000, all->print_depth);
	help(all);
	free(all->print_depth);
	free(all->img);
}
