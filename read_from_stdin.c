/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:41:03 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:25:39 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		error_exit(void)
{
	ft_putstr("\nERROR - Empty line after ##start or ##end\n");
	exit(0);
}

void			put_line(char *line)
{
	ft_putstr(line);
	ft_putstr("\n");
}

void			check_links_section(int links_section)
{
	if (links_section == 1)
	{
		ft_putstr("\nERROR - Link Expected\n");
		exit(0);
	}
}

int				check_comments(char **line)
{
	put_line(*line);
	if (ft_strcmp(*line, "##start") == 0)
	{
		free(*line);
		if (get_next_line(0, line) != 0)
			put_line(*line);
		else
			error_exit();
		return (2);
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		free(*line);
		if (get_next_line(0, line) != 0)
			put_line(*line);
		else
			error_exit();
		return (3);
	}
	else if (ft_strncmp(*line, "#", 1) == 0)
	{
		free(*line);
		return (1);
	}
	return (0);
}

t_list			*read_from_stdin(int *num_ants)
{
	char	*line;
	int		links_section;
	int		flag;
	t_list	*head;

	head = NULL;
	links_section = 0;
	grab_number_of_ants(num_ants);
	head = ft_lstnew(&head, sizeof(t_list*));
	while ((get_next_line(0, &line)) != 0)
	{
		flag = check_comments(&line);
		if (flag == 1)
			continue;
		else if (ft_strstr(line, "-"))
			links_action(&links_section, line, head);
		else
		{
			check_links_section(links_section);
			head = add_room(head, line, flag - 1);
		}
		*line ? free(line) : 0;
	}
	line ? free(line) : 0;
	return (head);
}
