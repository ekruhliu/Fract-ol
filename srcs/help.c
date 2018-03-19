/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:14:02 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 11:14:02 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	help(t_all *all)
{
	if (all->help == 1)
	{
		mlx_string_put(all->mlx, all->win, 5, 5, 0xFF0000, RSTRT);
		mlx_string_put(all->mlx, all->win, 5, 25, 0xFF0000, ON_CLR);
		mlx_string_put(all->mlx, all->win, 5, 45, 0xFF0000, DPTH);
		mlx_string_put(all->mlx, all->win, 5, 65, 0xFF0000, CLR);
		mlx_string_put(all->mlx, all->win, 5, 85, 0xFF0000, CH_FRCT);
		mlx_string_put(all->mlx, all->win, 5, 105, 0xFF0000, UP_DWN);
		mlx_string_put(all->mlx, all->win, 5, 125, 0xFF0000, LFT_RGHT);
		mlx_string_put(all->mlx, all->win, 5, 145, 0xFF0000, DGNL_MV_UP);
		mlx_string_put(all->mlx, all->win, 5, 165, 0xFF0000, DGNL_MV_DN);
	}
}
