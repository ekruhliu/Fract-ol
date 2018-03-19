/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:15:19 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 12:15:20 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	open_window(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIRINA, VISOTA, "Fractol");
}
