/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:52:05 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/31 13:52:06 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_apply(t_coord *c, t_matrix *m, t_coord *center)
{
	int cp_x;
	int cp_y;
	int cp_z;

	c->x -= center->x;
	c->y -= center->y;	
	cp_x = c->x;
	cp_y = c->y;
	cp_z = c->z;
	c->x = m->a1 * cp_x + m->a2 * cp_y + m->a3 * cp_z + m->a4 * c->s;
	c->y = m->b1 * cp_x + m->b2 * cp_y + m->b3 * cp_z + m->b4 * c->s;
	c->z = m->c1 * cp_x + m->c2 * cp_y + m->c3 * cp_z + m->c4 * c->s;
	c->x += center->x;
	c->y += center->y;
}

void	matrix_apply_caller(t_win *win, t_matrix *matrix)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < win->lines)
	{
		while (x < win->chars)
		{
			matrix_apply(win->coord[(y * win->chars) + x], matrix, win->center);
			x++;
		}
		y++;
	}
}

void    ft_reboot(int key, t_win *win)
{
	if (key == KEY_ESC || key == KEY_ENTER)
		exit(EXIT_SUCCESS);
	else if (key == KEY_C)
		ft_bzero(win->ptr, HEIGHT * WIDTH * 4);
}

void	ft_move(int key, t_win *win)
{
	t_matrix *matrix;

	if (key == KEY_RIGHT)
		matrix = move_use(win, MOVE_RIGHT, 0, 0);
	if (key == KEY_LEFT)
		matrix = move_use(win, MOVE_LEFT, 0, 0);
	if (key == KEY_UP)
		matrix = move_use(win, 0, MOVE_UP, 0);
	if (key == KEY_DOWN)
		matrix = move_use(win, 0, MOVE_DOWN, 0);
	matrix_apply_caller(win, matrix);
}

void	ft_scale(int key,t_win *win)
{

}

void	ft_color_switcher(int key,t_win *win)
{

}

int		what_key(int key, t_win *win)
{
	ft_reboot(key, win);
	ft_move(key, win);
	ft_scale(key, win);
	ft_color_switcher(key, win);
//	prepare_draw(win);
	return (0);
}