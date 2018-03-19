/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_complex_r_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:16:09 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 12:16:09 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	make_complex_r_f(t_all *all)
{
	if (all->w_t_f == 1)
	{
		MAX_REAL = 0.5;
		MIN_REAL = -2.0;
		MAX_FALSE = 1.25;
		MIN_FALSE = -1.25;
	}
	if (all->w_t_f == 5)
	{
		MAX_REAL = 1.5;
		MIN_REAL = -3.0;
		MAX_FALSE = 2.0;
		MIN_FALSE = -2.0;
	}
	if (all->w_t_f != 1 && all->w_t_f != 5)
	{
		MAX_REAL = 2;
		MIN_REAL = -2.0;
		MAX_FALSE = 2;
		MIN_FALSE = -2.0;
	}
	potoki_3(all);
}
