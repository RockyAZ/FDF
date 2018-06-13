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

void	ft_reboot(int key, t_win *win)
{
	if (key == KEY_ESC || key == KEY_ENTER)
	{
		system("leaks -quiet fdf");
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_C)
		ft_bzero(win->ptr, HEIGHT * WIDTH * 4);
}

static double	center_calc(t_win *win, char c)
{
	if (win->mouse.mouse_center == -1)
	{
		if (c == 'x')
			return (win->center.x);
		else
			return (win->center.y);
	}
	else
	{
		if (c == 'x')
			return (win->mouse.x);
		else
			return (win->mouse.y);
	}
}

void			matrix_apply(t_win *win, t_coord *cd1, t_matrix *m)
{
	double cp[3];

	cd1->x -= center_calc(win, 'x');
	cd1->y -= center_calc(win, 'y');
	cp[0] = m->a1 * cd1->x + m->a2 * cd1->y + m->a3 * cd1->z + m->a4 * 1;
	cp[1] = m->b1 * cd1->x + m->b2 * cd1->y + m->b3 * cd1->z + m->b4 * 1;
	cp[2] = m->c1 * cd1->x + m->c2 * cd1->y + m->c3 * cd1->z + m->c4 * 1;
	cd1->x = cp[0];
	cd1->y = cp[1];
	cd1->z = cp[2];
	cd1->x += center_calc(win, 'x');
	cd1->y += center_calc(win, 'y');
}

void			matrix_apply_caller(t_win *win, t_matrix *mx)
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

int				what_key(int key, t_win *win)
{
	matrix_prepare(win);
	if (key == KEY_SHIFT)
		win->mouse.move_mod *= -1;
	pasx(key, win);
	if (key == KEY_TAB)
		win->mouse.mouse_center *= -1;
	ft_reboot(key, win);
	if (key >= 123 && key <= 126)
		ft_move(key, win, MOVE_KEY);
	if (key == KEY_MINUS || key == KEY_PLUS)
		ft_scale(key, win);
	if (key == KEY_A || key == KEY_W || key == KEY_D)
		ft_rotate(key, win, ANGLE_X);
	prepare_draw(win);
	return (0);
}
