/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   klavochka.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:11:15 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/13 21:11:16 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	color_on(t_all *all)
{
	if (all->color_on == 0)
	{
		all->color = 0x0FF0F0;
		all->color_on = 1;
	}
	magik(all);
}

void	color_off(t_all *all)
{
	if (all->color_on == 1)
	{
		all->color = 0xF0F0F0;
		all->color_on = 0;
	}
	magik(all);
}

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

// void	restart(t_all *all)
// {
// 	// int i;

// 	// i = 0;
// 	all->complex_2 = all->tmp;
// 	all->complex_mouse_X = all->tmp_complex_mouse_X;
// 	all->complex_mouse_Y = all->tmp_complex_mouse_Y;
// 	// while (i < PIXELS)
// 	// {
// 	// 	all->complex_2[i] = all->tmp[i];
// 	// 	i++;
// 	// }
// 	magik(all);
// }

int		klavochka(int key, t_all *all)
{
	if (key == 53)
		exit_x();
	if (key == 69 || key == 78)
		(key == 69 ? depth_plus(all) : depth_minus(all));
	if (key == 1)
		(key == 1 && all->color_on == 0 ? color_on(all) : color_off(all));
	// if (key == 15)
		// restart(all);
	if ((key == 116) || (key == 121))
		(key == 116 ? color_plus(all) : color_minus(all));
	if (key == 4)
	{
		all->help = (all->help == 0 ? 1 : 0);
		magik(all);
	}
	if ((key == 43 || key == 47) && (all->w_t_f > 0 && all->w_t_f <= 10))
	{
		if (key == 47 && all->w_t_f < 10)
			all->w_t_f += 1;
		if (key == 43 && all->w_t_f > 1)
			all->w_t_f -= 1;
		make_complex_R_F(all);
		magik(all);
	}
	if (key == 13 || key == 7 || key == 126 || key == 125)
		(key == 13 || key == 126 ? move_up(all) : move_down(all));
	if (key == 0 || key == 123 || key == 2 || key == 124)
		(key == 0 || key == 123 ? move_left(all) : move_right(all));
	if (key == 12 || key == 14)
		(key == 12 ? dgnl_move_u_l(all) : dgnl_move_u_r(all));
	if (key == 6 || key == 8)
		(key == 6 ? dgnl_move_d_l(all) : dgnl_move_d_r(all));
	if ((B) || (G) || (R))
	{
		if (B)
			all->color = 0xF;
		if (G)
			all->color = 0x0F00;
		if (R)
			all->color = 0x100001; 
		magik(all);
	}
	return (0);
}
