/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:30:56 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 16:30:56 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

static	void	part_1(char *argv_1, char *str, char *tmp)
{
	str = ft_strjoin(str, argv_1);
	tmp = str;
	str = ft_strjoin(tmp, " & ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
}

static	void	part_2(char *argv_2, char *argv_3, char *str, char *tmp)
{
	tmp = str;
	str = ft_strjoin(tmp, argv_2);
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, " & ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, argv_3);
	free(tmp);
}

void			three_fractals(char *argv_1, char *argv_2, char *argv_3)
{
	char		*str;
	char		*tmp;

	tmp = NULL;
	str = malloc(sizeof(char) * 10);
	str = "./fractol ";
	part_1(argv_1, str, tmp);
	part_2(argv_2, argv_3, str, tmp);
	system(str);
	free(str);
}
