/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:55:23 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/30 16:35:57 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_valid_at(char (*t)[5], int y, int x)
{
	if (x == 4 && t[y][x] != '\n')
		return (0);
	if (0 <= x && x <= 3 && t[y][x] != '.' && t[y][x] != '#')
		return (0);
	return (1);
}

int		count_connections(char (*t)[5], int y, int x)
{
	int	res;

	res = 0;
	if (y > 0 && t[y - 1][x] == '#')
		res++;
	if (y < 3 && t[y + 1][x] == '#')
		res++;
	if (x > 0 && t[y][x - 1] == '#')
		res++;
	if (x < 3 && t[y][x + 1] == '#')
		res++;
	return (res);
}

int		valid_buf(const char *buf)
{
	int		y;
	int		x;
	int		num_conn;
	int		num_sharps;
	char	(*t)[5];

	t = (char(*)[5])buf;
	num_conn = 0;
	num_sharps = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 5)
		{
			if (t[y][x] == '#')
			{
				num_conn += count_connections(t, y, x);
				num_sharps += 1;
			}
			if (!is_valid_at(t, y, x))
				return (0);
		}
	}
	return (num_sharps == 4 && (num_conn == 6 || num_conn == 8));
}
