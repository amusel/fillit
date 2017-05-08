/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:39:54 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/27 15:47:59 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_fucking_map(char map[16][16], int size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			write(1, map[y][x] ? &map[y][x] : ".", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int		ft_sqrt(int n)
{
	int		res;

	res = 1;
	while (res * res < n)
		res++;
	return (res);
}

int		ft_lstlen(t_tetrimino *t)
{
	int		res;

	res = 1;
	while (t->next)
	{
		t = t->next;
		res++;
	}
	return (res);
}
