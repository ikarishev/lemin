/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:31:05 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:36:13 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				ants_in_start(t_list *rooms)
{
	int		start_ants;
	t_list	*curr;

	curr = rooms;
	start_ants = -100;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_start == 0)
			break ;
		curr = curr->next;
	}
	start_ants = ((t_room*)(curr->content))->num_ants;
	return (start_ants);
}

int				start_empty(t_list *rooms)
{
	t_list	*curr;

	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_start == 0)
		{
			if (((t_room*)(curr->content))->num_ants == 0)
				return (1);
			else
				return (0);
		}
		curr = curr->next;
	}
	return (0);
}

void			reset_rooms(t_list *rooms)
{
	clear_reservations(rooms);
	reset_distance(rooms);
	set_distance_from_start(rooms);
}

void			clear_reservations(t_list *rooms)
{
	t_list	*curr;

	curr = rooms;
	while (curr->next != NULL)
	{
		((t_room*)(curr->content))->reserved = 0;
		curr = curr->next;
	}
}

int				available_start_links(t_list *rooms)
{
	t_list	*curr;
	t_list	*curr2;
	t_room	*temp;

	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_start == 0)
			break ;
		curr = curr->next;
	}
	curr2 = ((t_room*)(curr->content))->links;
	while (curr2->next != NULL)
	{
		temp = (t_room*)((t_list*)(curr2->content))->content;
		if (temp->reserved == 0)
			return (1);
		curr2 = curr2->next;
	}
	return (0);
}
