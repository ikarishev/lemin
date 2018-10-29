/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocker_cascade_check4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:11:48 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:16:14 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_path_len(t_room *temp, t_list *rooms,
		int *dis, int *total_path_length)
{
	if (temp->distance_from_start != -100)
	{
		*dis = 0;
		*total_path_length = *total_path_length +
			pull_from_closest_dis(temp, rooms, *dis);
	}
}

int		get_total_path_length(t_list *rooms)
{
	t_list	*curr;
	t_list	*curr2;
	t_room	*temp;
	int		total_path_length;
	int		dis;

	curr = rooms;
	total_path_length = 0;
	dis = 0;
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
		get_path_len(temp, rooms, &dis, &total_path_length);
		curr2 = curr2->next;
	}
	return (total_path_length);
}

void	set_best(int *total_path_length, t_list **curr,
		t_list **best, t_list *rooms)
{
	if (*total_path_length == -100)
	{
		*total_path_length = get_total_path_length(rooms);
		*best = *curr;
	}
	else if (*total_path_length > get_total_path_length(rooms))
	{
		*total_path_length = get_total_path_length(rooms);
		*best = *curr;
	}
}
