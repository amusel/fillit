/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:17:39 by alischyn          #+#    #+#             */
/*   Updated: 2016/12/27 15:48:14 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include <unistd.h>

# define PARSE_SUCCESS(s) { *(s) = 1; return (0); }
# define PARSE_ERROR(s) { *(s) = 0; return (0); }
# define ABS(a) ((a) > 0 ? (a) : -(a))
# define MAX2(a, b) ((a) > (b) ? (a) : (b))
# define MAX4(a, b, c, d) (MAX2(MAX2(a, b), MAX2(c, d)))

typedef struct	s_tetrimino {
	char				points[4][4];
	int					ipoints[4][2];
	char				chr;
	int					width;
	int					height;
	struct s_tetrimino	*next;
}				t_tetrimino;

t_tetrimino		*parse(const char *filename);
t_tetrimino		*parse_next(int fd, int *success, size_t *nt, int expect);
t_tetrimino		*buf_to_tetrimino(const char *buf, size_t id);
void			tetrimino_set_ipoints(t_tetrimino *t);
void			tetrimino_set_width_height(t_tetrimino *t);

void			shift_tetrimino_y(t_tetrimino *t);
void			shift_tetrimino_x(t_tetrimino *t);
void			shift_tetrimino(t_tetrimino *t);

int				valid_buf(const char *block);

void			print_fucking_map(char map[16][16], int size);
int				ft_sqrt(int n);
int				ft_lstlen(t_tetrimino *t);

void			solve(t_tetrimino *t);
int				solve_recursion(char map[16][16],
									int map_size,
									t_tetrimino *t);

size_t			ft_strlen(const char *str);
void			ft_bzero(char *mem, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t count);

#endif
