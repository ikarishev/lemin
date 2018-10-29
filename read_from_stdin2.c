/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdin2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:24:27 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:26:05 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			links_action(int *links_section, char *line, t_list *head)
{
	*links_section = 1;
	make_link(head, line);
}
