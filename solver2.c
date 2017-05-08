/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:34:24 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/29 18:19:01 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place_fig(char map[16][16],
						int map_size,
						int cords[2],
						t_tetrimino *t)
{
	if (cords[0] + t->height > map_size ||
		cords[1] + t->width > map_size ||
		map[cords[0] + t->ipoints[0][0]][cords[1] + t->ipoints[0][1]] ||
		map[cords[0] + t->ipoints[1][0]][cords[1] + t->ipoints[1][1]] ||
		map[cords[0] + t->ipoints[2][0]][cords[1] + t->ipoints[2][1]] ||
		map[cords[0] + t->ipoints[3][0]][cords[1] + t->ipoints[3][1]])
		return (0);
	return (1);
}

void	place_fig(char map[16][16], int cords[2], t_tetrimino *t)
{
	map[cords[0] + t->ipoints[0][0]][cords[1] + t->ipoints[0][1]] = t->chr;
	map[cords[0] + t->ipoints[1][0]][cords[1] + t->ipoints[1][1]] = t->chr;
	map[cords[0] + t->ipoints[2][0]][cords[1] + t->ipoints[2][1]] = t->chr;
	map[cords[0] + t->ipoints[3][0]][cords[1] + t->ipoints[3][1]] = t->chr;
}

void	remove_fig(char map[16][16], int cords[2], t_tetrimino *t)
{
	map[cords[0] + t->ipoints[0][0]][cords[1] + t->ipoints[0][1]] = 0;
	map[cords[0] + t->ipoints[1][0]][cords[1] + t->ipoints[1][1]] = 0;
	map[cords[0] + t->ipoints[2][0]][cords[1] + t->ipoints[2][1]] = 0;
	map[cords[0] + t->ipoints[3][0]][cords[1] + t->ipoints[3][1]] = 0;
}

void	solve(t_tetrimino *t)
{
	char	map[16][16];
	int		map_size;

	map_size = ft_sqrt(ft_lstlen(t) * 4);
	ft_bzero((char *)map, sizeof(map));
	while (!solve_recursion(map, map_size, t) && map_size < 16)
	{
		map_size++;
		ft_bzero((char *)map, sizeof(map));
	}
	print_fucking_map(map, map_size);
}

int		solve_recursion(char map[16][16],
						int map_size,
						t_tetrimino *t)
{
	int			cords[2];

	if (!t)
		return (1);
	cords[0] = -1;
	while (++cords[0] < map_size)
	{
		cords[1] = -1;
		while (++cords[1] < map_size)
		{
			if (!can_place_fig(map, map_size, cords, t))
				continue ;
			place_fig(map, cords, t);
			if (solve_recursion(map, map_size, t->next))
				return (1);
			remove_fig(map, cords, t);
		}
	}
	return (0);
}
