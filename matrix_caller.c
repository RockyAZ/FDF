/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:43:41 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/11 18:43:41 by azaporoz         ###   ########.fr       */
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

void	ft_rotate(int key, t_win *win, double angle)
{
	if (key == KEY_W)
		rotate_x_use(angle, &win->matrix);
	if (key == KEY_D)
		rotate_y_use(angle,  &win->matrix);
	if (key == KEY_A)
		rotate_z_use(angle, &win->matrix);
	matrix_apply_caller(win, &win->matrix);
}

// void	ft_height(int key, t_win *win)
// {
// 	int		x;
// 	int		y;
// 	t_coord	v;

// 	y = 0;
// 	while (y < win->lines)
// 	{
// 		x = 0;
// 		while (x < win->chars)
// 		{
// 			v = get_coord(win, x, y);
// 			if (key == KEY_MULTI)
// 				v.z += 2;
// 			else
// 				v.z -= 2;
// 			x++;
// 		}
// 		y++;
// 	}
// 	matrix_apply_caller(win, &win->matrix);	
// }
