/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room_formatting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:37:35 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:20:02 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	error_exit(int flag, char *line)
{
	ft_putstr("ERROR - ");
	if (flag == 1)
		ft_putstr("Malformed line - no coordinates\n");
	else if (flag == 2)
		ft_putstr("Malformed line - missing coordinate\n");
	else if (flag == 3)
		ft_putstr("Malformed line - characters not expected\n");
	else if (flag == 4)
		ft_putstr("Malformed line - More or less than 3 substrings\n");
	else if (flag == 5)
		ft_putstr("Malformed line - Room starts with space character\n");
	else if (flag == 6)
		ft_putstr("Coordinate Overlap\n");
	else if (flag == 7)
		ft_putstr("Rooms not allowed to start with L ...kinda random\n");
	else
		ft_putstr("Malformed line - Unknown error\n");
	ft_putstr("(");
	ft_putstr(line);
	ft_putstr(")");
	exit(0);
}

void		check_rest(char *line, int i, int space_count)
{
	while (ft_isdigit(line[i]) && line[i] != '\0')
		i++;
	if (line[i] != '\0')
		error_exit(3, line);
	if (space_count != 2)
		error_exit(4, line);
}

void		check_line(char *line)
{
	int space_count;
	int i;

	space_count = 0;
	i = 0;
	if (line[i] == ' ')
		error_exit(5, line);
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == ' ')
	{
		space_count++;
		i++;
	}
	else if (line[i] == '\0')
		error_exit(1, line);
	while (ft_isdigit(line[i]) && line[i] != '\0')
		i++;
	if (line[i] == ' ')
		space_count++;
	else if (line[i] == '\0')
		error_exit(2, line);
	i++;
	check_rest(line, i, space_count);
}

void		check_coord_overlap(char *line, t_list *curr2)
{
	char	*line2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line2 = ((t_room*)(curr2->content))->name2;
	while (line[i] != ' ')
		i++;
	while (line2[j] != ' ')
		j++;
	if (strcmp(&line[i], &line2[j]) == 0)
		error_exit(6, line);
}

void		check_room_formatting(t_list *rooms)
{
	t_list	*curr;
	char	*line;

	curr = rooms;
	while (curr->next != NULL)
	{
		line = ((t_room*)(curr->content))->name2;
		if (line[0] == 'L')
			error_exit(7, line);
		check_line(line);
		check_coordinates(line, curr, rooms);
		curr = curr->next;
	}
}
