/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:56:07 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/02 18:56:07 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		window_prepare(t_win *win)
{
	int i;

	i = 0;
	if (!(win->mlx_ptr = mlx_init()) ||
	!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, win->name)))
		return (0);
	win->mouse.button_down = 0;
	win->mouse.move_mod = 1;
	win->mouse.mouse_center = -1;
	while (i++ < 2)
	{
		ft_move(KEY_RIGHT, win, MOVE_KEY);
		ft_rotate(KEY_D, win, ANGLE_X);
	}
	while (i++ < 5)
	{
		ft_move(KEY_DOWN, win, MOVE_KEY);
		ft_rotate(KEY_W, win, ANGLE_X);
	}
	i = 0;
	while (i < 6)
		win->pas[i++] = 0;
	return (1);
}

t_coord	*map_prepare(t_win *win, int x, int y, char *str)
{
	t_coord *coord;

	if (!(coord = (t_coord*)malloc(sizeof(t_coord))))
		error('m');
	coord->x = x * win->len;
	coord->y = y * win->len;
	coord->z = ft_atoi(str);
	coord->color = get_color(coord, coord->z);
	if (coord->z < win->lim_z[0])
		win->lim_z[0] = coord->z;
	if (coord->z > win->lim_z[1])
		win->lim_z[1] = coord->z;
	return (coord);
}

void	matrix_prepare(t_win *win)
{
	win->matrix.a1 = 0;
	win->matrix.a2 = 0;
	win->matrix.a3 = 0;
	win->matrix.a4 = 0;
	win->matrix.b1 = 0;
	win->matrix.b2 = 0;
	win->matrix.b3 = 0;
	win->matrix.b4 = 0;
	win->matrix.c1 = 0;
	win->matrix.c2 = 0;
	win->matrix.c3 = 0;
	win->matrix.c4 = 0;
	win->matrix.d1 = 0;
	win->matrix.d2 = 0;
	win->matrix.d3 = 0;
	win->matrix.d4 = 0;
}

void	center_prepare(t_win *win)
{
	double x;
	double y;

	x = (win->coord[0]->x + win->coord[win->lines * win->chars - 1]->x) / 2;
	y = (win->coord[0]->y + win->coord[win->lines * win->chars - 1]->y) / 2;
	win->center.x = x;
	win->center.y = y;
}
