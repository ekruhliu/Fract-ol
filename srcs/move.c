/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:07:39 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 19:07:40 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	move_up(t_all *all)
{
	MAX_FALSE = MAX_FALSE + 0.1;
	MIN_FALSE = MIN_FALSE + 0.1;
	potoki_3(all);
	magik(all);
}

void	move_down(t_all *all)
{
	MAX_FALSE = MAX_FALSE - 0.1;
	MIN_FALSE = MIN_FALSE - 0.1;
	potoki_3(all);
	magik(all);
}

void	move_left(t_all *all)
{
	MAX_REAL = MAX_REAL + 0.1;
	MIN_REAL = MIN_REAL + 0.1;
	potoki_3(all);
	magik(all);
}

void	move_right(t_all *all)
{
	MAX_REAL = MAX_REAL - 0.1;
	MIN_REAL = MIN_REAL - 0.1;
	potoki_3(all);
	magik(all);
}
