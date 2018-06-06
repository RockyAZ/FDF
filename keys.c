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

	cp_x = cd1->x;
	cp_y = cd1->y;
	cp_z = cd1->z;
	cd1->x -= win->center.x;
	cd1->y -= win->center.y;
	cd1->x = m->a1 * cp_x + m->a2 * cp_y + m->a3 * cp_z + m->a4 * 1;
	cd1->y = m->b1 * cp_x + m->b2 * cp_y + m->b3 * cp_z + m->b4 * 1;
	cd1->z = m->c1 * cp_z + m->c2 * cp_z + m->c3 * cp_z + m->c4 * 1;
	cd1->x += win->center.x;
	cd1->y += win->center.y;
}

void    matrix_apply_caller(t_win *win, t_matrix *mx)
{

	int x;
	int y;
	t_coord *cd1;

//write(1, "a\n", 2);

	y = 0;
//	 printf("%d\n", win->lines);
//write(1, "b\n", 2);

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
	t_matrix *matrix;

	if (key == KEY_RIGHT)
		matrix = move_use(len, 0, 0);
	if (key == KEY_LEFT)
		matrix = move_use(-len, 0, 0);
	if (key == KEY_UP)
		matrix = move_use(0, -len, 0);
	if (key == KEY_DOWN)
		matrix = move_use(0, len, 0);
	center_prepare(win);
	matrix_apply_caller(win, matrix);
	free(matrix);
}

void	ft_scale(int key, t_win *win)
{
	t_matrix *matrix;

	if (key == KEY_PLUS)
		matrix = scale_use(MOVE_IN);
	if (key == KEY_MINUS)
		matrix = scale_use(MOVE_OUT);
	matrix_apply_caller(win, matrix);
	free(matrix);
}

void	ft_rotate(int key, t_win *win)
{
	print_coord(win, 4);
	t_matrix *matrix;

	if (key == KEY_W)
		matrix = rotate_x_use(ANGLE_X);
	if (key == KEY_D)
		matrix = rotate_y_use(ANGLE_Y);
	if (key == KEY_A)
		matrix = rotate_z_use(ANGLE_Z);
	matrix_apply_caller(win, matrix);
	free(matrix);
}

void	ft_color_switcher(int key, t_win *win)
{

}

int		what_key(int key, t_win *win)
{
	ft_reboot(key, win);
	if (key >= 123 && key <= 126)
		ft_move(key, win,);
	if (key == KEY_MINUS || key == KEY_PLUS)
		ft_scale(key, win);
	if ((key >=0 && key <= 2) || key == KEY_W)
		ft_rotate(key, win);
//	ft_color_switcher(key, win);
	prepare_draw(win);
	return (0);
}
