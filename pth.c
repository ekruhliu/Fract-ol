/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:03:35 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/14 17:03:36 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	potoki_work(pthread_t *potok, t_all *all)
{
	pthread_create(&potok[0], 0, depth_part_1, (void*)all);
	pthread_create(&potok[1], 0, depth_part_2, (void*)all);
	pthread_create(&potok[2], 0, depth_part_3, (void*)all);
	pthread_create(&potok[3], 0, depth_part_4, (void*)all);
}

static void	potoki_work_2(pthread_t *potok, t_all *all)
{
	pthread_create(&potok[0], 0, lines_part_1, (void*)all);
	pthread_create(&potok[1], 0, lines_part_2, (void*)all);
	pthread_create(&potok[2], 0, lines_part_3, (void*)all);
	pthread_create(&potok[3], 0, lines_part_4, (void*)all);
}

void	potoki(t_all *all)
{
	pthread_t	potok[4];

	potoki_work(potok, all);
	pthread_join(potok[0], 0);
	pthread_join(potok[1], 0);
	pthread_join(potok[2], 0);
	pthread_join(potok[3], 0);
	potoki_work_2(potok, all);
	pthread_join(potok[0], 0);
	pthread_join(potok[1], 0);
	pthread_join(potok[2], 0);
	pthread_join(potok[3], 0);
}