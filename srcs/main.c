/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:51:00 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/01 18:51:01 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"
#include <sys/types.h>

static	void	cleaner(t_all *all)
{
	free(all->complex);
	free(all->complex_2);
	free(all->img);
	free(all->print_depth);
	free(all);
}

static	void	part_2(t_all *all)
{
	open_window(all);
	magik(all);
	mlx_hook(all->win, 6, 0, mouse, all);
	mlx_mouse_hook(all->win, zoom, all);
	mlx_hook(all->win, 17, 1L << 17, exit_x, 0);
	mlx_hook(all->win, 2, 5, klavochka, all);
	mlx_loop(all->mlx);
	cleaner(all);
}

static	void	part_1(char *argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->w_t_f = ft_atoi(argv);
	if (all->w_t_f < 1 || all->w_t_f > 10)
		error();
	make_coordinate(all);
	all->complex = malloc(sizeof(t_complex));
	make_complex_r_f(all);
	all->help = 0;
	all->depth = 50;
	all->color = 0xf0f0f0;
	all->color_on = 0;
	part_2(all);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		part_1(argv[1]);
	else if (argc == 3)
		two_fractals(argv[1], argv[2]);
	else if (argc == 4)
		three_fractals(argv[1], argv[2], argv[3]);
	else if (argc == 5)
		four_fractals(argv[1], argv[2], argv[3], argv[4]);
	else
		usage();
}
