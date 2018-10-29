/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:36:43 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:41:32 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_stuff(int ant_name, char *room_name)
{
	ft_putstr("L");
	ft_putnbr(ant_name);
	ft_putstr("-");
	ft_putstr(room_name);
	ft_putstr(" ");
}

void			move_one_from_closest(t_room *closest, t_room *room)
{
	closest->num_ants = closest->num_ants - 1;
	room->ant_name = closest->ant_name;
	if (closest->distance_from_start != 0)
		closest->reserved = 1;
	if (closest->distance_from_start == 0)
		closest->ant_name = closest->ant_name + 1;
	room->num_ants = room->num_ants + 1;
	print_stuff(room->ant_name, room->name);
	room->reserved = 1;
}

int				should_be_closest(t_room *temp, t_room *room)
{
	if ((temp->distance_from_start < room->distance_from_start)
			&& (temp->reserved == 0)
			&& (temp->distance_from_start != -2))
		return (1);
	else
		return (0);
}

int				better_closest(t_room *temp, t_room *closest)
{
	if (closest != NULL)
	{
		if ((temp->distance_from_start < closest->distance_from_start)
				&& (temp->reserved == 0)
				&& (temp->distance_from_start != -2))
			return (1);
	}
	return (0);
}

void			move_ant_closest(t_room *closest, t_room *room)
{
	if (closest->num_ants > 0)
		move_one_from_closest(closest, room);
}
