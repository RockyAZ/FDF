/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:02:58 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/13 13:02:59 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_coord *coord, double z)
{
	if (z < 0)
		coord->color = 0x14ff03;
	else if (z >= 0 && z <= 3)
		coord->color = 0x4dff4a;
	else if (z > 3 && z <= 6)
		coord->color = 0x7aff83;
	else if (z > 6 && z <= 9)
		coord->color = 0xb8ffc4;
	else
		coord->color = 0xedfff2;
	return (coord->color);
}

t_coord	get_coord(t_win *win, int x, int y)
{
	return (*win->coord[(y * win->chars) + x]);
}

void	str_out(t_win *win)
{
	char *x;
	char *y;

	x = ft_itoa(win->coord[0]->x);
	y = ft_itoa(win->coord[0]->y);
	if (win->mouse.move_mod == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, PINK, "MODE: MOVING");
	else
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, PINK, "MODE: ROTATE");
	if (win->mouse.mouse_center == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 60, PINK,
		"CENTER: MOUSE POSITION");
	else
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 60, PINK,
		"CENTER: CENTER MAP");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 75, BLUE,
	"press [TAB] to change CENTER mod");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 15, BLUE,
	"press [SHIFT] to change MAIN mod");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 30, RED, "X: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 30, GREEN, x);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 45, RED, "Y: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 45, GREEN, y);
	free(x);
	free(y);
}
