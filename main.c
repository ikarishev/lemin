/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:26:45 by ikarishe          #+#    #+#             */
/*   Updated: 2018/06/15 16:09:24 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	start_end_exists(t_list *rooms)
{
	t_list	*curr;
	int		end_exists;
	int		start_exists;

	end_exists = 0;
	start_exists = 0;
	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_start == 0)
			start_exists = 1;
		if (((t_room*)(curr->content))->distance_from_end == 0)
			end_exists = 1;
		curr = curr->next;
	}
	if ((start_exists == 0) || (end_exists == 0))
	{
		ft_putstr("ERROR - Start or End room missing\n");
		exit(0);
	}
}

void	set_ants_in_start(t_list *rooms, int num_ants)
{
	t_list *curr;

	curr = rooms;
	while (curr->next != NULL)
	{
		if (((t_room*)(curr->content))->distance_from_start == 0)
		{
			((t_room*)(curr->content))->num_ants = num_ants;
			((t_room*)(curr->content))->ant_name = 1;
		}
		curr = curr->next;
	}
}

int		main(void)
{
	t_list	*rooms;
	int		num_ants;

	num_ants = -1;
	rooms = NULL;
	rooms = read_from_stdin(&num_ants);
	check_room_formatting(rooms);
	start_end_exists(rooms);
	set_distance_from_start(rooms);
	set_distance_from_end(rooms);
	check_path_exists(rooms);
	set_ants_in_start(rooms, num_ants);
	ft_putstr("\nSOLUTION :\n\n");
	solve(rooms, num_ants);
}
