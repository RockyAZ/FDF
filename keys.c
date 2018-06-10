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

//	cd1->x -= win->center.x;
//	cd1->y -= win->center.y;
	cd1->x -= win->mouse.x;
	cd1->y -= win->mouse.y;	
	cp_x = cd1->x;
	cp_y = cd1->y;
	cp_z = cd1->z;
	cd1->x = m->a1 * cp_x + m->a2 * cp_y + m->a3 * cp_z + m->a4 * 1;
	cd1->y = m->b1 * cp_x + m->b2 * cp_y + m->b3 * cp_z + m->b4 * 1;
	cd1->z = m->c1 * cp_z + m->c2 * cp_z + m->c3 * cp_z + m->c4 * 1;
//	cd1->x += win->center.x;
//	cd1->y += win->center.y;
	cd1->x += win->mouse.x;
	cd1->y += win->mouse.y;	
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

void    ft_reboot(int key, t_win *win)
{
	if (key == KEY_ESC || key == KEY_ENTER)
	{
		system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_C)
		ft_bzero(win->ptr, HEIGHT * WIDTH * 4);
}

void	ft_move(int key, t_win *win, int len)
{
	if (key == KEY_RIGHT || key == MOUSE_SCROLL_RIGHT)
		move_use(len, 0, 0, &win->matrix);
	if (key == KEY_LEFT || key == MOUSE_SCROLL_LEFT)
		move_use(-len, 0, 0, &win->matrix);
	if (key == KEY_UP || key == MOUSE_SCROLL_UP)
		move_use(0, -len, 0, &win->matrix);
	if (key == KEY_DOWN || key == MOUSE_SCROLL_DOWN)
		move_use(0, len, 0, &win->matrix);
	center_prepare(win);
	matrix_apply_caller(win, &win->matrix);
}

void	ft_scale(int key, t_win *win)
{
	if (key == KEY_PLUS || key == MOUSE_SCROLL_UP)
		scale_use(MOVE_IN, &win->matrix);
	if (key == KEY_MINUS || key == MOUSE_SCROLL_DOWN)
		scale_use(MOVE_OUT, &win->matrix);
	matrix_apply_caller(win, &win->matrix);
}

void	ft_rotate(int key, t_win *win)
{
	if (key == KEY_W)
		rotate_x_use(ANGLE_X, &win->matrix);
	if (key == KEY_D)
		rotate_y_use(ANGLE_Y, &win->matrix);
	if (key == KEY_A)
		rotate_z_use(ANGLE_Z, &win->matrix);
	matrix_apply_caller(win, &win->matrix);
}
/*
void	ft_color_switcher(int key, t_win *win)
{

}
*/
int		what_key(int key, t_win *win)
{
	matrix_prepare(win);
	if (key == KEY_SHIFT)
		win->mouse.move_mod *= -1;
	ft_reboot(key, win);
	if (key >= 123 && key <= 126)
		ft_move(key, win, MOVE_KEY);
	if (key == KEY_MINUS || key == KEY_PLUS)
		ft_scale(key, win);
	if ((key >=0 && key <= 2) || key == KEY_W)
		ft_rotate(key, win);
	prepare_draw(win);
	return (0);
}
