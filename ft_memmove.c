/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:16:13 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/03 16:49:16 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (cdest < csrc)
	{
		i = 0;
		while (i++ < n)
			*(cdest++) = *(csrc++);
	}
	else if (cdest > csrc)
	{
		i = n;
		cdest += n - 1;
		csrc += n - 1;
		while (i-- > 0)
			*(cdest--) = *(csrc--);
	}
	return (dest);
}
