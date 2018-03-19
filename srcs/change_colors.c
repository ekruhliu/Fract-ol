/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:39:07 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/16 09:39:07 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	color_plus(t_all *all)
{
	if (all->color < 0x7FFFFFFF)
		all->color += 1;
	else
		all->color = 1;
	magik(all);
}

void	color_minus(t_all *all)
{
	if (all->color > 0)
		all->color -= 1;
	else
		all->color = 0x7FFFFFFF;
	magik(all);
}

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
