/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_exists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:18:12 by ikarishe          #+#    #+#             */
/*   Updated: 2018/06/15 15:49:07 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_start_end_direct(t_list *rooms)
{
	t_list *curr;
	t_list *curr2;
	t_room *temp;

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
		if (temp->distance_from_start == 0)
			return (1);
		curr2 = curr2->next;
	}
	return (0);
}

void	check_end_connected(t_list *rooms)
{
	t_list	*curr;
	int		path_exists;

	path_exists = 0;
	curr = rooms;
	while (curr->next != NULL)
	{
		if ((((t_room*)(curr->content))->distance_from_end != 0)
				&& (((t_room*)(curr->content))->distance_from_end != -2)
				&& (((t_room*)(curr->content))->distance_from_end != -100))
		{
			path_exists = 1;
			break ;
		}
		curr = curr->next;
	}
	if (check_start_end_direct(rooms))
		path_exists = 1;
	if (path_exists)
		return ;
	else
	{
		ft_putstr("ERROR - No path found - End room not connected\n");
		exit(0);
	}
}

void	check_start_connected(t_list *rooms)
{
	t_list	*curr;
	int		path_exists;

	path_exists = 0;
	curr = rooms;
	while (curr->next != NULL)
	{
		if ((((t_room*)(curr->content))->distance_from_start != 0)
				&& (((t_room*)(curr->content))->distance_from_start != -2)
				&& (((t_room*)(curr->content))->distance_from_start != -100))
		{
			path_exists = 1;
			break ;
		}
		curr = curr->next;
	}
	if (check_start_end_direct(rooms))
		path_exists = 1;
	if (path_exists)
		return ;
	else
	{
		ft_putstr("ERROR - No path found - Start room not connected\n");
		exit(0);
	}
}

void	check_path_exists(t_list *rooms)
{
	check_end_connected(rooms);
	check_start_connected(rooms);
}
