/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:57:51 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 13:57:52 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	usage(void)
{
	ft_putstr("\033[1;31musage: ./fractol [ NUMBER OF FRACRAL ]\n\e[m");
}

void	error(void)
{
	ft_putstr("\033[1;31mERROR!!! Invalid fractal number!\n\e[m");
	exit(1);
}
