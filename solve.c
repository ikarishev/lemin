/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:37:14 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 15:14:38 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			pull_from_closest(t_room *room, t_list *rooms)
{
	t_room	*closest;
	t_list	*curr2;
	t_room	*temp;

	closest = NULL;
	if (room->distance_from_start == 0)
	{
		set_new_distance(rooms);
		return ;
	}
	curr2 = room->links;
	while (curr2->next != NULL)
	{
		temp = (t_room*)((t_list*)(curr2->content))->content;
		if (should_be_closest(temp, room))
			closest = temp;
		if (better_closest(temp, closest))
			closest = temp;
		curr2 = curr2->next;
	}
	if (closest == NULL)
		return ;
	room->last_pull = closest;
	move_ant_closest(closest, room);
	pull_from_closest(closest, rooms);
}

void			pull_from_last(t_room *room, t_list *rooms)
{
	t_room *last;

	last = NULL;
	last = room->last_pull;
	if (last == NULL)
		return ;
	if (last->distance_from_start == 0)
		last->ant_name = last->ant_name + 1;
	move_ant_closest(last, room);
	pull_from_last(last, rooms);
}

static void		move_one_ant(t_list *curr, t_room *temp, int *ants_in_end)
{
	((t_room*)(curr->content))->num_ants =
		((t_room*)(curr->content))->num_ants + 1;
	((t_room*)(curr->content))->ant_name = temp->ant_name;
	print_stuff(((t_room*)(curr->content))->ant_name,
			((t_room*)(curr->content))->name);
	temp->num_ants = temp->num_ants - 1;
	if (temp->distance_from_start == 0)
		temp->ant_name = temp->ant_name + 1;
	*ants_in_end = *ants_in_end + 1;
}

void			pull_from_end(t_list *rooms, int *ants_in_end)
{
	t_list	*curr;
	t_list	*curr2;
	t_room	*temp;

	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_end == 0)
			break ;
		curr = curr->next;
	}
	curr2 = ((t_room*)(curr->content))->links;
	while (curr2->next != NULL)
	{
		temp = (t_room*)((t_list*)(curr2->content))->content;
		if (temp->num_ants > 0 && temp->reserved != 1)
			move_one_ant(curr, temp, ants_in_end);
		if (temp->distance_from_start != -100)
			pull_from_closest(temp, rooms);
		curr2 = curr2->next;
	}
}

void			solve(t_list *rooms, int num_ants)
{
	int ants_in_end;
	int movement;

	ants_in_end = 0;
	sort_end_links(rooms, num_ants);
	while (ants_in_end != num_ants)
	{
		reset_rooms(rooms);
		if (start_empty(rooms))
		{
			movement = 1;
			push_all_remaining(rooms, &ants_in_end, 1);
			while (movement)
				movement = push_all_remaining(rooms, &ants_in_end, 0);
			ft_putstr("\n");
			continue;
		}
		pull_from_end(rooms, &ants_in_end);
		if (num_ants == ants_in_start(rooms))
		{
			ft_putstr("ERROR - No path found\n");
			exit(0);
		}
		ft_putstr("\n");
	}
}
