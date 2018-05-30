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

void ft_line_draw(t_win *win, int x0, int y0, int x1, int y1, int color)
{
	int i;
	int dx = ft_abs(x1-x0);
	int dy = ft_abs(y1-y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy);//поделить на 2?->    ) / 2;
	int cp_err;

	while (x0 <= x1 && y0 <= y1)
	{
	i = (x0 * 4) + (y0 * win->size_line);
		win->ptr[i] = 255;
		win->ptr[++i] = 255;
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
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, win->img_x, win->img_y);
}

void ft_start(t_win *win)
{
	if (!win->check)
	{
		win->x0 = 20;
		win->y0 = 20;
		win->x1 = 20;
		win->y1 = 20;
	}
	else
		win->check++;
}

void    drawer(t_win *win)
{
	int x;
	int y;

//	win->check = 0;
		win->x1 = win->x0;
		win->y1 = win->y0;
//	ft_start(win);
	while (++y <= win->lines)
	{
		x = 0;
		win->x1 = win->x0;
		while (++x <= win->chars)
		{
			if (x < win->chars)
				ft_line_draw(win, win->x1, win->y1, win->x1 + LENGTH, win->y1, WHITE);
			if (y < win->lines)
				ft_line_draw(win, win->x1, win->y1, win->x1, win->y1 + LENGTH, WHITE);
			win->x1 += LENGTH;
		}
		win->y1 += LENGTH;
	}

}
