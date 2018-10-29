/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocker_cascade_check2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:00:01 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:06:10 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		put_progress_bar(int max)
{
	int p_bar;

	p_bar = 0;
	ft_putstr("WARNING - This map is quite large...\n");
	ft_putstr("Results not guaranteed\n");
	ft_putstr("Blocker cascade check may take a while..\n");
	ft_putstr("Progress Bar Enabled\n|");
	while (p_bar < max)
	{
		write(1, "-", 1);
		p_bar++;
	}
	write(1, "|\n|", 2);
}

void		reset_1(t_list *rooms)
{
	clear_reservations(rooms);
	reset_distance(rooms);
	set_distance_from_start(rooms);
}

void		reset_2(t_list *rooms, int num_ants)
{
	reset_ants(rooms);
	set_ants_in_start(rooms, num_ants);
}

void		reset(t_list *rooms, t_list **curr, t_list **nth_position,
		int num_ants)
{
	reset_1(rooms);
	swap(*curr, *nth_position);
	*curr = (*curr)->next;
	reset_2(rooms, num_ants);
}

void		reset_ants(t_list *rooms)
{
	t_list *curr;

	curr = rooms;
	while (curr->next != NULL)
	{
		((t_room*)(curr->content))->num_ants = 0;
		((t_room*)(curr->content))->ant_name = 0;
		((t_room*)(curr->content))->last_pull = NULL;
		curr = curr->next;
	}
}
