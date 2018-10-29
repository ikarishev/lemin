/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room_formatting2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:17:15 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:19:10 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_coordinates(char *line, t_list *curr, t_list *rooms)
{
	t_list	*curr2;

	curr2 = rooms;
	(void)line;
	while (curr2->next != NULL)
	{
		if (curr != curr2)
			check_coord_overlap(line, curr2);
		curr2 = curr2->next;
	}
}
