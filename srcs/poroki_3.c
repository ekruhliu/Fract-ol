/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poroki_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:42:54 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/19 11:42:55 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

static	void	potoki_work_3(pthread_t *potok_3, t_all *all)
{
	pthread_create(&potok_3[0], 0, make_comlpex_x_y_part_1, (void*)all);
	pthread_create(&potok_3[1], 0, make_comlpex_x_y_part_2, (void*)all);
	pthread_create(&potok_3[2], 0, make_comlpex_x_y_part_3, (void*)all);
	pthread_create(&potok_3[3], 0, make_comlpex_x_y_part_4, (void*)all);
}

void			potoki_3(t_all *all)
{
	pthread_t	potok_3[4];

	potoki_work_3(potok_3, all);
	pthread_join(potok_3[0], 0);
	pthread_join(potok_3[1], 0);
	pthread_join(potok_3[2], 0);
	pthread_join(potok_3[3], 0);
}
