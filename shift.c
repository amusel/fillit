/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:56:24 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/26 21:37:54 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_tetrimino_x(t_tetrimino *t)
{
	size_t	i;

	if (t->points[0][0] == '.' && t->points[1][0] == '.' &&
		t->points[2][0] == '.' && t->points[3][0] == '.')
	{
		i = 0;
		while (i < 3)
		{
			t->points[0][i] = t->points[0][i + 1];
			t->points[1][i] = t->points[1][i + 1];
			t->points[2][i] = t->points[2][i + 1];
			t->points[3][i] = t->points[3][i + 1];
			t->points[0][i + 1] = '.';
			t->points[1][i + 1] = '.';
			t->points[2][i + 1] = '.';
			t->points[3][i + 1] = '.';
			i++;
		}
		shift_tetrimino_x(t);
	}
}

void	shift_tetrimino_y(t_tetrimino *t)
{
	size_t	i;

	if (t->points[0][0] == '.' && t->points[0][1] == '.' &&
			t->points[0][2] == '.' && t->points[0][3] == '.')
	{
		i = 0;
		while (i < 3)
		{
			t->points[i][0] = t->points[i + 1][0];
			t->points[i][1] = t->points[i + 1][1];
			t->points[i][2] = t->points[i + 1][2];
			t->points[i][3] = t->points[i + 1][3];
			t->points[i + 1][0] = '.';
			t->points[i + 1][1] = '.';
			t->points[i + 1][2] = '.';
			t->points[i + 1][3] = '.';
			i++;
		}
		shift_tetrimino_y(t);
	}
}

void	shift_tetrimino(t_tetrimino *t)
{
	shift_tetrimino_x(t);
	shift_tetrimino_y(t);
}
