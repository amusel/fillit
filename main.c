/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:15:37 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/27 15:46:46 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int		main(int argc, const char **argv)
{
	t_tetrimino	*t;

	if (argc != 2)
	{
		write(1, "Usage: ./fillit tetriminos.fillit\n", 34);
		return (0);
	}
	t = parse(argv[1]);
	if (!t)
		write(1, "error\n", 6);
	else
		solve(t);
	return (0);
}
