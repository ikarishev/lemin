/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocker_cascade_check3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:07:06 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 15:23:19 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_end_links(t_list *rooms)
{
	t_list	*curr;
	t_list	*curr2;
	int		end_links;

	end_links = 0;
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
		end_links++;
		curr2 = curr2->next;
	}
	return (end_links);
}

int		get_start_links(t_list *rooms)
{
	t_list	*curr;
	t_list	*curr2;
	int		start_links;

	curr = rooms;
	start_links = 0;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_start == 0)
			break ;
		curr = curr->next;
	}
	curr2 = ((t_room*)(curr->content))->links;
	while (curr2->next != NULL)
	{
		start_links++;
		curr2 = curr2->next;
	}
	return (start_links);
}

int		get_max_possible_moves(t_list *rooms)
{
	int		end_links;
	int		start_links;

	end_links = get_end_links(rooms);
	start_links = get_start_links(rooms);
	if (end_links > start_links)
		return (start_links);
	else
		return (end_links);
}

int		if_temp_closest(t_room *temp, t_room *room)
{
	if ((temp->distance_from_start < room->distance_from_start)
			&& (temp->reserved == 0)
			&& (temp->distance_from_start != -2))
		return (1);
	return (0);
}

int		if_better_closest(t_room *temp, t_room *closest)
{
	if ((temp->distance_from_start < closest->distance_from_start)
			&& (temp->reserved == 0)
			&& (temp->distance_from_start != -2))
		return (1);
	return (0);
}
