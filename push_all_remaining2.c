/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_remaining2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:20:47 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:24:09 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push_one_ant(t_list *curr, t_room *temp,
		int *ants_in_end, int *movement)
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
	*movement = *movement + 1;
}
