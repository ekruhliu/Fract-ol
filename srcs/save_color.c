/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:17:13 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 12:17:13 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	save_color(t_all *all, int color, int i)
{
	int		red;
	int		green;
	int		blue;

	red = (color >> 16);
	green = (color >> 8) - (red << 8);
	blue = (color) - (red << 16) - (green << 8);
	all->complex_2[i].red = red;
	all->complex_2[i].green = green;
	all->complex_2[i].blue = blue;
}
