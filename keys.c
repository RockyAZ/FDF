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

void matrix_apply(t_win *win, t_coord *cd1, t_matrix *m)
{
	double cp_x;
	double cp_y;
	double cp_z;

	if (win->mouse.mouse_center == -1)
	{
		cd1->x -= win->center.x;
		cd1->y -= win->center.y;
	}
	else
	{
		cd1->x -= win->mouse.x;
		cd1->y -= win->mouse.y;
	}
//	cp_x = cd1->x;
//	cp_y = cd1->y;
//	cp_z = cd1->z;
//	cd1->x = m->a1 * cp_x + m->a2 * cp_y + m->a3 * cp_z + m->a4 * 1;
//	cd1->y = m->b1 * cp_x + m->b2 * cp_y + m->b3 * cp_z + m->b4 * 1;
//	cd1->z = m->c1 * cp_z + m->c2 * cp_z + m->c3 * cp_z + m->c4 * 1;
	cp_x = m->a1 * cd1->x + m->a2 * cd1->y + m->a3 * cd1->z + m->a4 * 1;
	cp_y = m->b1 * cd1->x + m->b2 * cd1->y + m->b3 * cd1->z + m->b4 * 1;
	cp_z = m->c1 * cd1->x + m->c2 * cd1->y + m->c3 * cd1->z + m->c4 * 1;
	cd1->x = cp_x;
	cd1->y = cp_y;
	cd1->z = cp_z;
	if (win->mouse.mouse_center == -1)
	{
		cd1->x += win->center.x;
		cd1->y += win->center.y;
	}
	else
	{
		cd1->x += win->mouse.x;
		cd1->y += win->mouse.y;
	}
}

void    matrix_apply_caller(t_win *win, t_matrix *mx)
{
	int x;
	int y;

	y = 0;
	while (y < win->lines)
	{
		x = 0;
		while (x < win->chars)
		{			
			matrix_apply(win, win->coord[(y * win->chars) + x], mx);
			x++;
		}
		y++;
	}
}
/*
void	ft_color_switcher(int key, t_win *win)
{

}
*/

int		what_key(int key, t_win *win)
{
	matrix_prepare(win);
//	pasx(key, win);
	if (key == KEY_SHIFT)
		win->mouse.move_mod *= -1;
	if (key == KEY_TAB)
		win->mouse.mouse_center *= -1;
	ft_reboot(key, win);
	if (key >= 123 && key <= 126)
		ft_move(key, win, MOVE_KEY);
	if (key == KEY_MINUS || key == KEY_PLUS)
		ft_scale(key, win);
	if ((key >=0 && key <= 2) || key == KEY_W)
		ft_rotate(key, win, ANGLE_X);
	prepare_draw(win);
	return (0);
}
