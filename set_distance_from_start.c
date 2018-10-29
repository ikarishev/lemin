/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_distance_from_start.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:57:27 by ikarishe          #+#    #+#             */
/*   Updated: 2018/06/11 13:12:36 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		set_from_closest_neighbor(t_list *rooms)
{
	t_list	*curr;
	t_list	*curr2;
	t_room	*temp;

	curr = rooms;
	while (curr->next != NULL)
	{
		curr2 = ((t_room*)(curr->content))->links;
		while (curr2->next != NULL)
		{
			temp = (t_room*)((t_list*)(curr2->content))->content;
			if (temp->distance_from_start >= 0 &&
					((t_room*)(curr->content))->distance_from_start == -1)
				((t_room*)(curr->content))->distance_from_start =
					temp->distance_from_start + 1;
			if (temp->distance_from_start >= 0 &&
					((t_room*)(curr->content))->distance_from_start >
					(temp->distance_from_start + 1))
				((t_room*)(curr->content))->distance_from_start =
					temp->distance_from_start + 1;
			curr2 = curr2->next;
		}
		curr = curr->next;
	}
}

static void		deal_with_dead_links(t_list *rooms)
{
	t_list *curr;

	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_start == -1)
			((t_room*)(curr->content))->distance_from_start = -100;
		curr = curr->next;
	}
}

static int		get_checksum(t_list *rooms)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = rooms;
	while (curr->next != NULL)
	{
		i = i + ((t_room*)(curr->content))->distance_from_start;
		curr = curr->next;
	}
	return (i);
}

void			set_distance_from_start(t_list *rooms)
{
	int		checksum;

	checksum = get_checksum(rooms);
	while (1)
	{
		set_from_closest_neighbor(rooms);
		if (checksum == get_checksum(rooms))
			break ;
		else
			checksum = get_checksum(rooms);
	}
	deal_with_dead_links(rooms);
}
