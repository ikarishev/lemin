/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:18:04 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/19 16:46:01 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char *s;

	s = str1;
	while (n > 0)
	{
		*s++ = *(char *)str2++;
		n--;
	}
	return (str1);
}
