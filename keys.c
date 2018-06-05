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

/*
void	matrix_apply(t_coord *c, t_matrix *m, t_coord *center)
{
	double cp_x;
	double cp_y;
	double cp_z;

//	c->x -= center->x;
//	c->y -= center->y;
	cp_x = m->a1 * c->x + m->a2 * c->y + m->a3 * c->z + m->a4 * 1;
	cp_y = m->b1 * c->x + m->b2 * c->y + m->b3 * c->z + m->b4 * 1;
	cp_z = m->c1 * c->x + m->c2 * c->y + m->c3 * c->z + m->c4 * 1;
	c->x = cp_x;
	c->y = cp_y;
	c->z = cp_z;
//	c->x += center->x;
//	c->y += center->y;
	printf("\n--------------\ncd1::%f\n", c->x);
	printf("cd1::%f\n", c->y);
	printf("cd1::%f\n-------------\n\n", c->z);
}


void	matrix_apply_caller(t_win *win, t_matrix *matrix)
{
	int x;
	int y;

	y = 0;
	while (y < win->lines)
	{
	x = 0;
		while (x < win->chars)
		{
			matrix_apply(get_coord(win, x, y), matrix, win->center);
			x++;
		}
		y++;
	}
}
*/

void matrix_apply(t_win *win, t_coord *cd1, t_matrix *m)
{
	double cp_x;
	double cp_y;
	double cp_z;

	cp_x = cd1->x;
	cp_y = cd1->y;
	cp_z = cd1->z;
//	cd1->x -= win->center->x;
//	cd1->y -= win->center->y;
	cd1->x = m->a1 * cp_x + m->a2 * cp_y + m->a3 * cp_z + m->a4 * 1;
	cd1->y = m->b1 * cp_x + m->b2 * cp_y + m->b3 * cp_z + m->b4 * 1;
	cd1->z = m->c1 * cp_z + m->c2 * cp_z + m->c3 * cp_z + m->c4 * 1;
//	printf("\n--------------\ncd1::%f\n", cd1->x);
//	printf("cd1::%f\n", cd1->y);
//	printf("cd1::%f\n-------------\n\n", cd1->z);
//	cd1->x += win->center->x;
//	cd1->y += win->center->y;
}

void    matrix_apply_caller(t_win *win, t_matrix *mx)
{
	int x;
	int y;
	t_coord *cd1;

	y = 0;
	while (y < win->lines)
	{
		x = 0;
		while (x < win->chars)
		{
//			cd1 = get_coord(win, x, y);
				matrix_apply(win, get_coord(win, x, y), mx);
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
	free(matrix);
}

void	ft_scale(int key,t_win *win)
{

}

void	ft_color_switcher(int key,t_win *win)
{

}

int		what_key(int key, t_win *win)
{
//print_coord(win, 9);
//	printf("\n\n\n\n");
	ft_reboot(key, win);
	ft_move(key, win);
//	ft_scale(key, win);
//	ft_color_switcher(key, win);
//print_coord(win, 9);
//	draw_image(win);
prepare_draw(win);
	return (0);
}
