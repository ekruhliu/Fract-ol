/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poroki_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:42:49 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 11:42:49 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

static	void	potoki_work_2(pthread_t *potok_2, t_all *all)
{
	pthread_create(&potok_2[0], 0, lines_part_1, (void*)all);
	pthread_create(&potok_2[1], 0, lines_part_2, (void*)all);
	pthread_create(&potok_2[2], 0, lines_part_3, (void*)all);
	pthread_create(&potok_2[3], 0, lines_part_4, (void*)all);
}

void			potoki_2(t_all *all)
{
	pthread_t	potok_2[4];

	potoki_work_2(potok_2, all);
	pthread_join(potok_2[0], 0);
	pthread_join(potok_2[1], 0);
	pthread_join(potok_2[2], 0);
	pthread_join(potok_2[3], 0);
}
