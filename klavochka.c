/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   klavochka.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:11:15 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/13 21:11:16 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		klavochka(int key, t_all *all)
{
	if (key == 53)
		exit_x();
	if (key == 69 || key == 78)
		(key == 69 ? depth_plus(all) : depth_minus(all));
	// if (key == 126 || key == 125)
	// 	(key == 126 ? move_up(all) : move_down(all));
	// if (key == 123 || key == 124)
	// 	(key == 123 ? move_left(all) : move_right(all));
	return (0);
}
