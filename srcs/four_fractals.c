/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:31:11 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 16:31:12 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

static	void	part_1(char *ar_1, char *str, char *tmp)
{
	str = ft_strjoin(str, ar_1);
	tmp = str;
	str = ft_strjoin(tmp, " & ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
}

static	void	part_2(char *ar_2, char *ar_3, char *str, char *tmp)
{
	tmp = str;
	str = ft_strjoin(tmp, ar_2);
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, " & ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, ar_3);
	free(tmp);
}

static	void	part_3(char *ar_4, char *str, char *tmp)
{
	tmp = str;
	str = ft_strjoin(tmp, " & ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, ar_4);
	free(tmp);
}

void			four_fractals(char *ar_1, char *ar_2, char *ar_3, char *ar_4)
{
	char		*str;
	char		*tmp;

	tmp = NULL;
	str = malloc(sizeof(char) * 10);
	str = "./fractol ";
	part_1(ar_1, str, tmp);
	part_2(ar_2, ar_3, str, tmp);
	part_3(ar_4, str, tmp);
	system(str);
	free(str);
}
