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
	if (!(win->mlx_ptr = mlx_init()) ||
	!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, win->name)))
		return (0);
	win->mouse.button_down = 0;
	win->mouse.move_mod = 1;
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

t_coord get_coord(t_win *win, int x, int y)
{
	return(*win->coord[(y * win->chars) + x]);
}

void	center_prepare(t_win *win)
{
	double x;
	double y;

	x = (((win->chars - 1) / 2.0f) + win->coord[0]->x / 100) * win->len;
	y = (((win->lines - 1) / 2.0f) + win->coord[0]->y / 100) * win->len;
//	x = ((win->chars - 1) / 2.0f) * win->len;
//	y = ((win->lines - 1) / 2.0f) * win->len;
//	printf("x_win::%f\n", win->coord[0]->x);
//	printf("y_win::%f\n", win->coord[0]->y);	
//	printf("CALC_X::%d\n", (((win->chars - 1) / 2) + (int)win->coord[0]->x) * win->len);
//	printf("CALC_Y::%d\n", (((win->lines - 1) / 2) + (int)win->coord[0]->y) * win->len);
//printf("XX::%f\n", x);
//printf("YY::%f\n", y);

	win->center.x = x;
	win->center.y = y;
}

void print_coord(t_win *win, int j)
{
//	system("clear");
	if (j == 0)
		j = win->lines * win->chars;
	for(int i = 0; i < j; i++)
	{
		printf("x:%f\n", win->coord[i]->x);
		printf("y:%f\n", win->coord[i]->y);
		printf("z:%f\n\n\n", win->coord[i]->z);		
	}
	printf("-----------------\n");
}
