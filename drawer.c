/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:13:44 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/25 18:13:44 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void ft_line_draw(t_win *win, double x0, double y0, double x1, double y1, int color)
{
	int i;
	double dx = fabs(x1 - x0);
	double dy = fabs(y1 - y0);
	double sx = x0 < x1 ? 1 : -1;
	double sy = y0 < y1 ? 1 : -1;
	double err = (dx > dy ? dx : -dy);//поделить на 2?->    ) / 2;
	double cp_err;

	while (x0 <= x1 && y0 <= y1)
	{
	i = (x0 * 4) + (y0 * win->size_line);
		win->ptr[i] = 100;
		win->ptr[++i] = 0;
		win->ptr[++i] = 0;

		cp_err = err;
		if (cp_err > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (cp_err < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
*/
void ft_line_draw(t_win *win, t_coord *cd1, t_coord *cd2)
{
	int i;
	double dx = fabs(cd2->x - cd1->x);
	double dy = fabs(cd2->y - cd1->y);
	double sx = cd1->x < cd2->x ? 1 : -1;
	double sy = cd1->y < cd2->y ? 1 : -1;
	double err = (dx > dy ? dx : -dy) / 2;//поделить на 2?->    ) / 2;
	double cp_err;

	while (cd1->x <= cd2->x && cd1->y <= cd2->y)
	{
	i = (cd1->x * 4) + (cd1->y * win->size_line);
		win->ptr[i] = 100;
		win->ptr[++i] = 0;
		win->ptr[++i] = 0;

		cp_err = err;
		if (cp_err > -dx)
		{
			err -= dy;
			cd1->x += sx;
		}
		if (cp_err < dy)
		{
			err += dx;
			cd1->y += sy;
		}
	}
}


void    draw_image(t_win *win)
{
	int x;
	int y;

	while (y < win->lines)
	{
		x = 0;
		while (x < win->chars)
		{
			if (x < win->chars)
				ft_line_draw(win, win->coord[y * win->chars + x]);
			if (y < win->lines)
				ft_line_draw(win, win->x1, win->y1, win->x1, win->y1 + LENGTH, WHITE);
			win->x1 += LENGTH;
		}
		win->y1 += LENGTH;
	}

}

void	prepare_draw(t_win *win)
{
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->ptr = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
	draw_image(win);
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}
