/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:25:23 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/26 21:58:02 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

t_tetrimino	*parse(const char *filename)
{
	int			fd;
	int			success;
	t_tetrimino	*res;
	size_t		num_tetrimino;

	success = 1;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	num_tetrimino = 0;
	res = parse_next(fd, &success, &num_tetrimino, 0);
	close(fd);
	return (success ? res : 0);
}

t_tetrimino	*parse_next(int fd, int *success, size_t *nt, int expect)
{
	char		buf[21];
	size_t		num_read;
	t_tetrimino	*res;

	buf[20] = 0;
	num_read = read(fd, buf, 20);
	if (num_read == 0 && *success == 1 && !expect)
		PARSE_SUCCESS(success)
	if (num_read < 20 || !valid_buf((char *)buf) || *nt == 26)
		PARSE_ERROR(success)
	res = buf_to_tetrimino((char *)buf, *nt);
	(*nt)++;
	if (read(fd, buf, 1) == 1)
	{
		if (buf[0] == '\n')
			res->next = parse_next(fd, success, nt, 1);
		else
			PARSE_ERROR(success)
	}
	return (res);
}

t_tetrimino		*buf_to_tetrimino(const char *buf, size_t id)
{
	t_tetrimino	*res;
	size_t		i;

	res = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	i = 0;
	while (i < 4)
	{
		res->points[0][i] = buf[i];
		res->points[1][i] = buf[5 + i];
		res->points[2][i] = buf[10 + i];
		res->points[3][i] = buf[15 + i];
		i++;
	}
	res->chr = 'A' + id;
	res->next = 0;
	shift_tetrimino(res);
	tetrimino_set_ipoints(res);
	tetrimino_set_width_height(res);
	return (res);
}

void			tetrimino_set_ipoints(t_tetrimino *t)
{
	int		x;
	int		y;
	int		id;

	id = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (t->points[y][x] == '#')
			{
				t->ipoints[id][0] = y;
				t->ipoints[id][1] = x;
				id++;
			}
		}
	}
}

void			tetrimino_set_width_height(t_tetrimino *t)
{
	t->width = 0;
	t->height = 0;
	t->height = MAX4(t->ipoints[0][0],
						t->ipoints[1][0],
						t->ipoints[2][0],
						t->ipoints[3][0]);
	t->width = MAX4(t->ipoints[0][1],
						t->ipoints[1][1],
						t->ipoints[2][1],
						t->ipoints[3][1]);
	t->height += 1;
	t->width += 1;
}
