/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:39:30 by ikarishe          #+#    #+#             */
/*   Updated: 2018/06/15 14:06:19 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	link_error(void)
{
	ft_putstr("\nERROR - Link creation failed\n");
	exit(0);
}

void	set_link(int buff, char first[buff], char second[buff], t_list *head)
{
	t_list	*curr;
	t_list	*node;
	t_list	*room_one;
	t_list	*room_two;

	room_one = NULL;
	room_two = NULL;
	curr = head;
	while (curr->next != NULL)
	{
		if ((ft_strcmp(first, ((t_room*)(curr->content))->name) == 0))
			room_one = curr;
		if ((ft_strcmp(second, ((t_room*)(curr->content))->name) == 0))
			room_two = curr;
		curr = curr->next;
	}
	if (room_one != NULL && room_two != NULL)
	{
		node = ft_lstnew(room_two, sizeof(t_list*));
		ft_lstadd(&(((t_room*)(room_one->content))->links), node);
		node = ft_lstnew(room_one, sizeof(t_list*));
		ft_lstadd(&(((t_room*)(room_two->content))->links), node);
	}
	else
		link_error();
}

void	make_link(t_list *head, char *line)
{
	char	first[ft_strlen(line)];
	char	second[ft_strlen(line)];
	int		i;
	int		j;

	i = 0;
	ft_bzero(first, ft_strlen(line));
	ft_bzero(second, ft_strlen(line));
	while (line[i] != '\0' && line[i] != '-')
	{
		first[i] = line[i];
		i++;
	}
	i++;
	j = 0;
	while (line[i] != '\0')
	{
		second[j] = line[i];
		j++;
		i++;
	}
	set_link(ft_strlen(line), first, second, head);
}
