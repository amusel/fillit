/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:55:18 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/23 16:36:13 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_strlen(const char *str)
{
	const char	*old;

	old = str;
	while (*str)
		str++;
	return (str - old);
}

void	ft_bzero(char *mem, size_t size)
{
	while (size--)
		*(mem++) = 0;
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
