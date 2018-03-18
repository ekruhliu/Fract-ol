/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:07:39 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 19:07:40 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	dgnl_move_u_l(t_all *all)
{
	all->complex->max_false = all->complex->max_false + 0.1;
	all->complex->min_false = all->complex->min_false + 0.1;
	all->complex->max_real = all->complex->max_real + 0.1;
	all->complex->min_real = all->complex->min_real + 0.1;
	potoki_3(all);
	magik(all);
}

void	dgnl_move_u_r(t_all *all)
{
	all->complex->max_false = all->complex->max_false + 0.1;
	all->complex->min_false = all->complex->min_false + 0.1;
	all->complex->max_real = all->complex->max_real - 0.1;
	all->complex->min_real = all->complex->min_real - 0.1;
	potoki_3(all);
	magik(all);
}

void	dgnl_move_d_l(t_all *all)
{
	all->complex->max_false = all->complex->max_false - 0.1;
	all->complex->min_false = all->complex->min_false - 0.1;
	all->complex->max_real = all->complex->max_real + 0.1;
	all->complex->min_real = all->complex->min_real + 0.1;
	potoki_3(all);
	magik(all);
}

void	dgnl_move_d_r(t_all *all)
{
	all->complex->max_false = all->complex->max_false - 0.1;
	all->complex->min_false = all->complex->min_false - 0.1;
	all->complex->max_real = all->complex->max_real - 0.1;
	all->complex->min_real = all->complex->min_real - 0.1;
	potoki_3(all);
	magik(all);
}

void	move_up(t_all *all)
{
	all->complex->max_false = all->complex->max_false + 0.1;
	all->complex->min_false = all->complex->min_false + 0.1;
	potoki_3(all);
	magik(all);
}

void	move_down(t_all *all)
{
	all->complex->max_false = all->complex->max_false - 0.1;
	all->complex->min_false = all->complex->min_false - 0.1;
	potoki_3(all);
	magik(all);
}

void	move_left(t_all *all)
{
	all->complex->max_real = all->complex->max_real + 0.1;
	all->complex->min_real = all->complex->min_real + 0.1;
	potoki_3(all);
	magik(all);
}

void	move_right(t_all *all)
{
	all->complex->max_real = all->complex->max_real - 0.1;
	all->complex->min_real = all->complex->min_real - 0.1;
	potoki_3(all);
	magik(all);
}
