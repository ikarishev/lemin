/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_end_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:16:37 by ikarishe          #+#    #+#             */
/*   Updated: 2018/06/27 12:44:08 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		not_sorted(t_list *curr2)
{
	t_list	*curr;
	t_room	*temp;
	int		dist;

	curr = curr2;
	dist = -100;
	while (curr->next != NULL)
	{
		temp = (t_room*)((t_list*)(curr->content))->content;
		if (temp->distance_from_start < dist)
			return (1);
		else
			dist = temp->distance_from_start;
		curr = curr->next;
	}
	return (0);
}

t_list	*find_furthest(t_list *curr2)
{
	t_list	*curr;
	t_list	*furthest;
	t_room	*temp;
	int		dist;

	curr = curr2;
	dist = -100;
	while (curr->next != NULL)
	{
		temp = (t_room*)((t_list*)(curr->content))->content;
		if (temp->reserved == 1)
			break ;
		if (temp->distance_from_start > dist)
		{
			furthest = curr;
			dist = temp->distance_from_start;
		}
		curr = curr->next;
	}
	return (furthest);
}

void	swap(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	put_furthest_last(t_list *curr2, t_list *furthest)
{
	t_list	*links;
	t_list	*reserve_check;
	t_list	*last_link;
	t_room	*temp;

	links = ((t_room*)(curr2->content))->links;
	while (links->next != NULL)
	{
		last_link = links;
		links = links->next;
		reserve_check = links;
		if (links->next != NULL)
		{
			temp = (t_room*)((t_list*)(reserve_check->content))->content;
			if (temp->reserved == 1)
				break ;
		}
	}
	temp = (t_room*)((t_list*)(furthest->content))->content;
	temp->reserved = 1;
	swap(furthest, last_link);
}

void	sort_end_links(t_list *rooms, int num_ants)
{
	t_list	*curr;
	t_list	*curr2;
	t_list	*furthest;

	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_end == 0)
			break ;
		curr = curr->next;
	}
	curr2 = ((t_room*)(curr->content))->links;
	while (not_sorted(curr2))
	{
		furthest = find_furthest(curr2);
		put_furthest_last(curr, furthest);
	}
	clear_reservations(rooms);
	blocker_cascade_check(rooms, curr, num_ants);
}
