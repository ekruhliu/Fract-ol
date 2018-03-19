/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:18:05 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 12:18:05 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	create_image(t_all *all)
{
	all->img = malloc(sizeof(t_img));
	all->img->bits = 0;
	all->img->size_line = 0;
	all->img->end = 0;
	all->img->image = mlx_new_image(all->mlx, WIRINA, VISOTA);
	all->img->line = mlx_get_data_addr(DATA_ADDR_1, DATA_ADDR_2);
}
