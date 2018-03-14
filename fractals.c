/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:45:28 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 13:45:29 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	fractals(t_all *all, int i)
{
	int	result;

	result = 0;
	if (all->w_t_f == 1)
		result = fractal_mandelbrot(all, i);
	if (all->w_t_f == 2)
		result = fractal_julia(all, i);
	if (all->w_t_f == 3)
		result = fractal_burnship(all, i);
	if (all->w_t_f == 4)
		result = fractal_test(all, i);
	return(result);
}
