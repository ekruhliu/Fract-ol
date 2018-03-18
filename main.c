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

#include "fract.h"

int	exit_x(void)
{
	exit(1);
}

void	open_window(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIRINA, VISOTA, "Fractol");
}

void	make_complex_R_F(t_all *all)
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

void	make_coordinate(t_all *all)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	all->complex_2 = malloc(sizeof(t_complex_2) * PIXELS);
	while (y < VISOTA)
	{
		x = 0;
		while (x < WIRINA)
		{
			all->complex_2[i].y = y;
			all->complex_2[i].x = x;
			i++;
			x++;
		}
		y++;
	}
}

void	ft_color_fill(t_all *all, int color, int i)
{
	int		red;
	int		green;
	int		blue;

	red = (color >> 16);
	green = (color >> 8) - (red << 8);
	blue = (color) - (red << 16) - (green << 8);
	all->complex_2[i].red = red;
	all->complex_2[i].green = green;
	all->complex_2[i].blue = blue;
}

void	create_image(t_all *all)
{
	all->img = malloc(sizeof(t_img));
	all->img->bits = 0;
	all->img->size_line = 0;
	all->img->end = 0;
	all->img->image = mlx_new_image(all->mlx, WIRINA, VISOTA);
	all->img->line = mlx_get_data_addr(DATA_ADDR_1, DATA_ADDR_2);
}

void	cleaner(t_all *all)
{
	free(all->complex);
	free(all->complex_2);
	free(all->img);
	// free(all->tmp);
	free(all);
}

// int		ft_isnumber(char c)
// {
// 	if (c >= 49 && c <= 57)
// 		return (1);
// 	return (0);
// }

// void	read_SI(t_all *all)
// {
// 	char	*tmp;

// 	while (get_next_line(STANDART_INPUT, &tmp) >= 0)
// 	{
// 		if (ft_isnumber(tmp) == 1)
// 			continue;
// 		all->w_t_f = ft_atoi(tmp);
// 		free(tmp);	
// 	}
// }

void	two_fractals(char *argv_1, char *argv_2)
{
	t_all	*all;
	t_all	*all_2;
	int		i;

	i = 0;
	all = malloc(sizeof(t_all));
	all->w_t_f = ft_atoi(argv_1);
	make_coordinate(all);
	all->complex = malloc(sizeof(t_complex));
	make_complex_R_F(all);
	all->help = 0;
	all->depth = 50;
	all->color = 0xf0f0f0; //0xFFF0F0
	all->color_on = 0;
	open_window(all);
	magik(all);
	mlx_hook(all->win, 6, 0, mouse, all);
	mlx_mouse_hook(all->win, zoom, all);
	mlx_hook(all->win, 17, 1L << 17, exit_x, 0);
	mlx_hook(all->win, 2, 5, klavochka, all);

	/* **************************** */

	i = 0;
	all_2 = malloc(sizeof(t_all));
	all_2->w_t_f = ft_atoi(argv_2);
	make_coordinate(all_2);
	all_2->complex = malloc(sizeof(t_complex));
	make_complex_R_F(all_2);
	all_2->help = 0;
	all_2->depth = 50;
	all_2->color = 0xf0f0f0; //0xFFF0F0
	all_2->color_on = 0;
	open_window(all_2);
	magik(all_2);
	mlx_hook(all_2->win, 6, 0, mouse, all_2);
	mlx_mouse_hook(all_2->win, zoom, all_2);
	mlx_hook(all_2->win, 17, 1L << 17, exit_x, 0);
	mlx_hook(all_2->win, 2, 5, klavochka, all_2);

	/* *************************** */

	mlx_loop(all->mlx);
	mlx_loop(all_2->mlx);
	cleaner(all);
	cleaner(all_2);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		i;

	if (argc >= 2 && argc <= 5)
	{
		if (argc == 2)
		{
			i = 0;
			all = malloc(sizeof(t_all));
			//read_SI(all);
			all->w_t_f = ft_atoi(argv[1]);
			make_coordinate(all);
			all->complex = malloc(sizeof(t_complex));
			make_complex_R_F(all);
			all->help = 0;
			all->depth = 50;
			all->color = 0xf0f0f0; //0xFFF0F0 0x7FFFFFFE
			all->color_on = 0;
			// all->tmp = all;
			open_window(all);
			magik(all);
			mlx_hook(all->win, 6, 0, mouse, all);
			mlx_mouse_hook(all->win, zoom, all);
			mlx_hook(all->win, 17, 1L << 17, exit_x, 0);
			mlx_hook(all->win, 2, 5, klavochka, all);
			mlx_loop(all->mlx);
			cleaner(all);
		}
		if (argc == 3)
			two_fractals(argv[1], argv[2]);
		// all->tmp = all->complex_2;//malloc(sizeof(t_complex_2) * PIXELS);
		// all->tmp_complex_mouse_X = all->complex_mouse_X;
		// all->tmp_complex_mouse_Y = all->complex_mouse_Y;	
	}
	else
		usage();
}