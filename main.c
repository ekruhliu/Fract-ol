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
		all->complex->max_real = 0.5;
		all->complex->min_real = -2.0;
		all->complex->max_false = 1.25;
		all->complex->min_false = -1.25;
	}
	else
	{
		all->complex->max_real = 2;
		all->complex->min_real = -2.0;
		all->complex->max_false = 2;
		all->complex->min_false = -2.0;
	}
}

void	make_complex_X_Y(t_all *all, int i)
{
	double	range_X;
	double	range_Y;

	range_X = 0;
	range_Y = 0;
	range_Y = (all->complex->max_false - all->complex->min_false) / VISOTA;
	all->complex_2[i].complex_Y = all->complex_2[i].y * range_Y + all->complex->min_false;
	range_X = (all->complex->max_real - all->complex->min_real) / WIRINA;
	all->complex_2[i].complex_X = all->complex_2[i].x * range_X + all->complex->min_real;
}

void	make_coordinate(t_all *all)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
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

void		create_lines(t_all *all, int i)
{
	int		x;

	if ((int)all->complex_2[i].y >= 0 && (int)all->complex_2[i].x >= 0)
	{
		if ((int)all->complex_2[i].y < VISOTA && (int)all->complex_2[i].x < WIRINA)
		{
			x = (int)all->complex_2[i].y * all->img->size_line + (int)all->complex_2[i].x * 4;
			if (x < VISOTA * WIRINA * 4)
			{
				all->img->line[x] = all->complex_2[i].blue;
				all->img->line[x + 1] = all->complex_2[i].green;
				all->img->line[x + 2] = all->complex_2[i].red;
			}
		}
	}
}

void	magik(t_all *all)
{
	int i;

	i = 0;
	all->ret_depth = 0;
	while (i < PIXELS)
	{
		all->ret_depth = fractals(all, i);
		if (all->ret_depth < all->depth) 
			ft_color_fill(all, (((all->ret_depth + 1) % (i + 1)) * all->color), i);
		else
			ft_color_fill(all, 0, i);
		i++;
	}
	i = 0;
	create_image(all);
	while (i < PIXELS)
	{
		create_lines(all, i);
		i++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img->image, 0, 0);
	free(all->img);
}

void	cleaner(t_all *all)
{
	free(all->complex);
	free(all->complex_2);
	free(all->img);
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

int	main(int argc, char **argv)
{
	t_all	*all;
	int		i;

	if (argc >= 2)
	{
		i = 0;
		all = malloc(sizeof(t_all));
		//read_SI(all);
		all->w_t_f = ft_atoi(argv[1]);
		all->complex = malloc(sizeof(t_complex));
		all->complex_2 = malloc(sizeof(t_complex_2) * PIXELS);
		make_coordinate(all);
		make_complex_R_F(all);
		while (i < PIXELS)
		{
			make_complex_X_Y(all, i);
			i++;
		}
		all->depth = 50;
		all->color = 0x0FF0F0; //0xFFF0F0
		open_window(all);
		magik(all);
		mlx_hook(all->win, 6, 0, mouse, all);
		mlx_mouse_hook(all->win, zoom, all);
		mlx_hook(all->win, 17, 1L << 17, exit_x, 0);
		mlx_hook(all->win, 2, 5, klavochka, all);
		mlx_loop(all->mlx);
	}
	else
		usage();
}