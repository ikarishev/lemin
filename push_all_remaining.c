/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_remaining.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:23:59 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:22:43 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push_loop(t_list *curr, t_list *curr2, t_room *temp, int *movement)
{
	while ((curr2->next != NULL) &&
			(((t_room*)(curr->content))->num_ants != 0))
	{
		temp = (t_room*)((t_list*)(curr2->content))->content;
		if (temp->reserved == 1)
		{
			curr2 = curr2->next;
			continue ;
		}
		if ((temp->distance_from_end <
					((t_room*)(curr->content))->distance_from_end)
				&& temp->distance_from_end != 0
				&& temp->distance_from_end != -2
				&& temp->reserved == 0 && temp->num_ants == 0)
		{
			temp->reserved = 1;
			((t_room*)(curr->content))->num_ants =
				((t_room*)(curr->content))->num_ants - 1;
			temp->num_ants = temp->num_ants + 1;
			temp->ant_name = ((t_room*)(curr->content))->ant_name;
			*movement = 1;
			print_stuff(temp->ant_name, temp->name);
		}
		curr2 = curr2->next;
	}
}

int		push(t_list *rooms)
{
	t_list	*curr;
	t_list	*curr2;
	t_room	*temp;
	int		movement;

	movement = 0;
	curr2 = NULL;
	curr = rooms;
	temp = NULL;
	while (curr->next != NULL)
	{
		if ((((t_room*)(curr->content))->num_ants > 0)
				&& (((t_room*)(curr->content))->distance_from_end != 0)
				&& (((t_room*)(curr->content))->reserved != 1))
			curr2 = ((t_room*)(curr->content))->links;
		if (curr2 != NULL)
		{
			push_loop(curr, curr2, temp, &movement);
		}
		curr2 = NULL;
		curr = curr->next;
	}
	return (movement);
}

void	pull_chain(t_room *room, int *movement)
{
	t_room *temp;

	temp = room->last_pull;
	if (temp == NULL)
		return ;
	if (temp->distance_from_start == 0)
		return ;
	if (temp->num_ants > 0)
	{
		temp->num_ants = temp->num_ants - 1;
		temp->reserved = 1;
		room->num_ants = room->num_ants + 1;
		room->reserved = 1;
		room->ant_name = temp->ant_name;
		print_stuff(room->ant_name, room->name);
		*movement = *movement + 1;
	}
	else
		temp->reserved = 0;
	pull_chain(temp, movement);
}

void	try_pull_chain(t_list *curr2, int *movement,
		t_list *curr, int *ants_in_end)
{
	t_room *temp;

	temp = (t_room*)((t_list*)(curr2->content))->content;
	if (temp->num_ants > 0)
		push_one_ant(curr, temp, ants_in_end, movement);
	pull_chain(temp, movement);
}

int		push_all_remaining(t_list *rooms, int *ants_in_end, int flag)
{
	t_list	*curr;
	t_list	*curr2;
	int		movement;

	movement = 0;
	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_end == 0)
			break ;
		curr = curr->next;
	}
	curr2 = ((t_room*)(curr->content))->links;
	if (flag)
	{
		while (curr2->next != NULL)
		{
			try_pull_chain(curr2, &movement, curr, ants_in_end);
			curr2 = curr2->next;
		}
	}
	else
		movement += push(rooms);
	return (movement);
}
