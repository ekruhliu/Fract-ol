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

static	void	part_1(char *argv_1, char **str)
{
	char	*new;
	
	new = ft_strjoin(*str, argv_1);
	free(*str);
	*str = new;
	new = ft_strjoin(*str, " & ./fractol ");
	free(*str);
	*str = new;
}

static	void	part_2(char *argv_2, char *argv_3, char **str)
{
	char	*new;
	
	new = ft_strjoin(*str, argv_2);
	free(*str);
	*str = new;
	new = ft_strjoin(*str, " & ./fractol ");
	free(*str);
	*str = new;
	new = ft_strjoin(*str, argv_3);
	free(*str);
	*str = new;
}

void			three_fractals(char *argv_1, char *argv_2, char *argv_3)
{
	char		*str;
	char		*tmp;

	tmp = ft_strnew(0);
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
	part_1(argv_1, &str);
	part_2(argv_2, argv_3, &str);
	system(str);
	free(str);
}
