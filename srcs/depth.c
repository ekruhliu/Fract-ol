/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:37:04 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 15:37:05 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	depth_plus(t_all *all)
{
	DEPTH += 1;
	magik(all);
}

void	depth_minus(t_all *all)
{
	DEPTH -= 1;
	magik(all);
}
