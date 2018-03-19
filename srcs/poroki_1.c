/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poroki_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:42:45 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 11:42:45 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

static	void	potoki_work(pthread_t *potok, t_all *all)
{
	pthread_create(&potok[0], 0, depth_part_1, (void*)all);
	pthread_create(&potok[1], 0, depth_part_2, (void*)all);
	pthread_create(&potok[2], 0, depth_part_3, (void*)all);
	pthread_create(&potok[3], 0, depth_part_4, (void*)all);
}

void			potoki(t_all *all)
{
	pthread_t	potok[4];

	potoki_work(potok, all);
	pthread_join(potok[0], 0);
	pthread_join(potok[1], 0);
	pthread_join(potok[2], 0);
	pthread_join(potok[3], 0);
}
