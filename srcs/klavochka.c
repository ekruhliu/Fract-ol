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

#include "../includes/fract.h"

static	void	part_1(int key, t_all *all)
{
	if (key == 53)
		exit(1);
	if (key == 69 || key == 78)
		(key == 69 ? depth_plus(all) : depth_minus(all));
	if (key == 1)
		(key == 1 && all->color_on == 0 ? color_on(all) : color_off(all));
	if ((key == 116) || (key == 121))
		(key == 116 ? color_plus(all) : color_minus(all));
	if (key == 4)
	{
		all->help = (all->help == 0 ? 1 : 0);
		magik(all);
	}
}

static	void	part_2(int key, t_all *all)
{
	if (key == 13 || key == 7 || key == 126 || key == 125)
		(key == 13 || key == 126 ? move_up(all) : move_down(all));
	if (key == 0 || key == 123 || key == 2 || key == 124)
		(key == 0 || key == 123 ? move_left(all) : move_right(all));
	if (key == 12 || key == 14)
		(key == 12 ? dgnl_move_u_l(all) : dgnl_move_u_r(all));
	if (key == 6 || key == 8)
		(key == 6 ? dgnl_move_d_l(all) : dgnl_move_d_r(all));
}

static	void	part_3(int key, t_all *all)
{
	if ((key == 43 || key == 47) && (all->w_t_f > 0 && all->w_t_f <= 10))
	{
		if (key == 47 && all->w_t_f < 10)
			all->w_t_f += 1;
		if (key == 43 && all->w_t_f > 1)
			all->w_t_f -= 1;
		make_complex_r_f(all);
		magik(all);
	}
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
}

int				klavochka(int key, t_all *all)
{
	part_1(key, all);
	part_2(key, all);
	part_3(key, all);
	return (0);
}
