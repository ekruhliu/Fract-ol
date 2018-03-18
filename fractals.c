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
		result = fractal_mandelbrot_4th(all, i);
	if (all->w_t_f == 5)
		result = fractal_celtic_mandelbrot(all, i);
	if (all->w_t_f == 6)
		result = fractal_verticat_mandelbrot_5th(all, i);
	if (all->w_t_f == 7)
		result = fractal_burnship_5th(all, i);
	if (all->w_t_f == 8)
		result = fractal_cubic_burnship(all, i);
	if (all->w_t_f == 9)
		result = fractal_imag_quasi_perpendicular(all, i);
	if (all->w_t_f == 10)
		result = fractal_celtic_5th_mbal(all, i);
	return(result);
}
