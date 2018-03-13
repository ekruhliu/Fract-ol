/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burnship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:18:49 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/13 21:18:52 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		fractal_burnship(t_all *all, int i)
{
	int		n;
	double	true_X;
	double	false_Y;
	double	tmp;

	n = 0;
	false_Y = 0;
	true_X = 0;
	while (n < all->depth)
	{
		tmp = (true_X * true_X) - (false_Y * false_Y);
		false_Y = 2 * fabs(true_X * false_Y) + all->complex_2[i].complex_Y;
		true_X = tmp + all->complex_2[i].complex_X;
		if ((true_X * true_X + false_Y * false_Y) > 4)
			break ;
		n++;
	}
	return (n);
}
