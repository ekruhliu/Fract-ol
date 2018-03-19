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

static	void	part_1(char *ar_1, char **str)
{
	char	*new;
	
	new = ft_strjoin(*str, ar_1);
	free(*str);
	*str = new;
	new = ft_strjoin(*str, " & ./fractol ");
	free(*str);
	*str = new;
}

static	void	part_2(char *ar_2, char *ar_3, char **str)
{
	char	*new;
	
	new = ft_strjoin(*str, ar_2);
	free(*str);
	*str = new;
	new = ft_strjoin(*str, " & ./fractol ");
	free(*str);
	*str = new;
	new = ft_strjoin(*str, ar_3);
	free(*str);
	*str = new;
}

static	void	part_3(char *ar_4, char **str)
{
	char	*new;
	
	new = ft_strjoin(*str, " & ./fractol ");
	free(*str);
	*str = new;
	new = ft_strjoin(*str, ar_4);
	free(*str);
	*str = new;
}

void			four_fractals(char *ar_1, char *ar_2, char *ar_3, char *ar_4)
{
	char		*str;
	char		*tmp;

	tmp = ft_strnew(0);
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
	part_1(ar_1, &str);
	part_2(ar_2, ar_3, &str);
	part_3(ar_4, &str);
	system(str);
	free(str);
}
