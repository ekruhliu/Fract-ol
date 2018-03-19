/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:41:29 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 11:41:30 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	dgnl_move_u_l(t_all *all)
{
	MAX_FALSE = MAX_FALSE + 0.1;
	MIN_FALSE = MIN_FALSE + 0.1;
	MAX_REAL = MAX_REAL + 0.1;
	MIN_REAL = MIN_REAL + 0.1;
	potoki_3(all);
	magik(all);
}

void	dgnl_move_u_r(t_all *all)
{
	MAX_FALSE = MAX_FALSE + 0.1;
	MIN_FALSE = MIN_FALSE + 0.1;
	MAX_REAL = MAX_REAL - 0.1;
	MIN_REAL = MIN_REAL - 0.1;
	potoki_3(all);
	magik(all);
}

void	dgnl_move_d_l(t_all *all)
{
	MAX_FALSE = MAX_FALSE - 0.1;
	MIN_FALSE = MIN_FALSE - 0.1;
	MAX_REAL = MAX_REAL + 0.1;
	MIN_REAL = MIN_REAL + 0.1;
	potoki_3(all);
	magik(all);
}

void	dgnl_move_d_r(t_all *all)
{
	MAX_FALSE = MAX_FALSE - 0.1;
	MIN_FALSE = MIN_FALSE - 0.1;
	MAX_REAL = MAX_REAL - 0.1;
	MIN_REAL = MIN_REAL - 0.1;
	potoki_3(all);
	magik(all);
}
