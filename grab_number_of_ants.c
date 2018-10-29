/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_number_of_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:03:09 by ikarishe          #+#    #+#             */
/*   Updated: 2018/06/08 15:15:43 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	error_exit(int flag)
{
	if (flag == 1)
	{
		ft_putstr("\nERROR - Non compliant line - Number of ants\n");
		exit(0);
	}
	else if (flag == 2)
	{
		ft_putstr("\nERROR - Invalid number of ants\n");
		exit(0);
	}
	else if (flag == 3)
	{
		ft_putstr("\nERROR - Number of ants - Will not attempt to");
		ft_putstr(" parse lines longer than 9 characters\n");
		exit(0);
	}
}

int			ft_str_digits_only(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void		grab_number_of_ants(int *num_ants)
{
	int		num;
	char	*line;

	num = 0;
	while ((get_next_line(0, &line)) != 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		if (ft_strncmp(line, "#", 1) == 0)
		{
			free(line);
			continue;
		}
		if (ft_strlen(line) > 9)
			error_exit(3);
		num = ft_atoi(line);
		break ;
	}
	if (!ft_str_digits_only(line))
		error_exit(1);
	if (num <= 0)
		error_exit(2);
	*num_ants = num;
	free(line);
	return ;
}
