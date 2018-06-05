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
		win->ptr[i] = 0;
		win->ptr[++i] = 0;
		win->ptr[++i] = 120;

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
	t_coord *cd1;

	y = 0;
	while (y < win->lines)
	{
		x = 0;
		while (x < win->chars)
		{
			cd1 = get_coord(win, x, y);
			if (x + 1 < win->chars)
				ft_line_draw(win, cd1, get_coord(win, x + 1, y));
			if (y + 1 < win->lines)
				ft_line_draw(win, cd1, get_coord(win, x, y + 1));
			x++;
		}
		y++;
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
