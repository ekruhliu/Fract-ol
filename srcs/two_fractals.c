/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:30:46 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 16:30:46 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	two_fractals(char *argv_1, char *argv_2)
{
	char		*str;
	char		*tmp;

	tmp = ft_strnew(0);
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
	tmp = ft_strjoin(str, argv_1);
	free(str);
	str = tmp;
	str = ft_strjoin(tmp, " & ./fractol ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, argv_2);
	free(tmp);
	system(str);
	free(str);
}
