/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:09:32 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 13:57:48 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

static void	check_for_bullshit(t_list *head, t_room *room, int flag)
{
	t_list *curr;

	curr = head;
	while (curr->next != NULL)
	{
		if (ft_strcmp(((t_room*)(curr->content))->name, room->name) == 0)
		{
			ft_putstr(room->name);
			ft_putstr("\nERROR - Room with that name already exists\n");
			exit(0);
		}
		if (flag == 1)
			if (((t_room*)(curr->content))->distance_from_start == 0)
			{
				ft_putstr("\nERROR - Start room alrady exists\n");
				exit(0);
			}
		if (flag == 2)
			if (((t_room*)(curr->content))->distance_from_end == 0)
			{
				ft_putstr("\nERROR - End room already exists\n");
				exit(0);
			}
		curr = curr->next;
	}
}

static void	error_exit(int flag)
{
	if (flag == 0)
	{
		ft_putstr("\nERROR - Unexpected comment location\n");
		exit(0);
	}
}

static void	error_check(char *line)
{
	if (ft_strncmp(line, "#", 1) == 0)
		error_exit(0);
}

t_list		*add_room(t_list *head, char *line, int flag)
{
	t_list	*node;
	t_room	room;
	int		i;
	char	name_buff[ft_strlen(line)];

	i = 0;
	error_check(line);
	ft_bzero(name_buff, ft_strlen(line));
	while (line[i] != ' ' && line[i] != '\0')
	{
		name_buff[i] = line[i];
		i++;
	}
	room.name = ft_strdup(name_buff);
	room.name2 = ft_strdup(line);
	check_for_bullshit(head, &room, flag);
	init_room(&room);
	if (flag == 1)
		init_start_room(&room);
	if (flag == 2)
		init_end_room(&room);
	room.links = ft_lstnew(NULL, sizeof(t_list*));
	node = ft_lstnew(&room, sizeof(room));
	ft_lstadd(&head, node);
	return (head);
}
