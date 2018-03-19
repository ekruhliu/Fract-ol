/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:16:45 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 12:16:46 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	make_coordinate(t_all *all)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	all->complex_2 = malloc(sizeof(t_complex_2) * PIXELS);
	while (y < VISOTA)
	{
		x = 0;
		while (x < WIRINA)
		{
			Y = y;
			X = x;
			i++;
			x++;
		}
		y++;
	}
}
