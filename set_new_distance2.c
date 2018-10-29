/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_distance2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:28:07 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:30:21 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			reset_distance(t_list *rooms)
{
	t_list	*curr;

	curr = rooms;
	while (curr->next != NULL)
	{
		if ((((t_room*)(curr->content))->distance_from_start != 0)
				&& (((t_room*)(curr->content))->distance_from_start != -2))
			((t_room*)(curr->content))->distance_from_start = -1;
		if (((t_room*)(curr->content))->reserved == 1)
			((t_room*)(curr->content))->distance_from_start = -100;
		curr = curr->next;
	}
}
