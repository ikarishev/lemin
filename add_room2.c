/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:56:48 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:06:27 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		init_start_room(t_room *room)
{
	room->distance_from_end = -2;
	room->distance_from_start = 0;
	room->ant_name = 1;
}

void		init_end_room(t_room *room)
{
	room->distance_from_start = -2;
	room->distance_from_end = 0;
}

void		init_room(t_room *room)
{
	room->distance_from_start = -1;
	room->distance_from_end = -1;
	room->reserved = 0;
	room->num_ants = 0;
	room->ant_name = 0;
	room->last_pull = NULL;
}
