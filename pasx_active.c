/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasx_active.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:28:24 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/11 18:28:25 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_circle(t_win *win, int x, int y, int color)
{
	int i;

	i = (x * 4) + (y * win->size_line);
	win->ptr[i] = color;
}

static void	draw_circle(t_win *win, int x0, int y0, int x, int y)
{
	// int i;

	// i = ((x0 + x) * 4) + ((y0 + y) * win->size_line);
	// win->ptr[i] = 255;
	// i = ((x0 + y) * 4) + ((y0 + x) * win->size_line);	
	// win->ptr[i] = 255;
	// i = ((x0 - y) * 4) + ((y0 + x) * win->size_line);
	// win->ptr[i] = 255;
	// i = ((x0 - x) * 4) + ((y0 + y) * win->size_line);
	// win->ptr[i] = 255;
	// i = ((x0 - x) * 4) + ((x0 - x) * win->size_line);
	// win->ptr[i] = 255;
	// i = ((x0 - y) * 4) + ((y0 - x) * win->size_line);
	// win->ptr[i] = 255;
	// i = ((x0 + y) * 4) + ((y0 - x) * win->size_line);
	// win->ptr[i] = 255;
	// i = ((x0 + x) * 4) + ((y0 - y) * win->size_line);
	// win->ptr[i] = 255;
	put_circle(win, x0 + x, y0 + y, WHITE);
	put_circle(win, x0 + y, y0 + x, WHITE);
	put_circle(win, x0 - y, y0 + x, WHITE);
	put_circle(win, x0 - x, y0 + y, WHITE);
	put_circle(win, x0 - x, y0 - y, WHITE);
	put_circle(win, x0 - y, y0 - x, WHITE);
	put_circle(win, x0 + y, y0 - x, WHITE);
	put_circle(win, x0 + x, y0 - y, WHITE);
}

void		get_circle(int x0, int y0, int radius, t_win *win)
{
	int x;
	int y;
	int dx;
	int dy;
	int err;

	x = radius - 1;
	y = 0;
	dx = 1;
	dy = 1;
	err = dx - (radius << 1);
	while (x >= y)
	{
		draw_circle(win, x0, y0, x, y);
		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}
		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}

static int	circle_moving(t_win *win)
{
	win->img_ptr = mlx_new_image(win->mlx_ptr, 400, 300);
	win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
	if (win->circle.x - win->circle.rad <= 0)
		win->circle.vx *= -1;
	if (win->circle.x + win->circle.rad >= 400)
		win->circle.vx *= -1;
	if (win->circle.y - win->circle.rad <= 0)
		win->circle.vy *= -1;
	if (win->circle.y + win->circle.rad >= 300)
		win->circle.vy *= -1;
	win->circle.x += 0.7 * win->circle.vx;
	win->circle.y += 0.7 * win->circle.vy;
	get_circle(win->circle.x, win->circle.y, win->circle.rad, win);	
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr_pasx, win->img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	return (0);
}

void		pasx_active(t_win *win)
{
	int i;

	i = 0;
	while (i < 6)
		win->pas[i++] = 0;
	win->win_ptr_pasx = mlx_new_window(win->mlx_ptr, 400, 300, "EPIC WIN!!!!!");
	win->circle.x = 20;
	win->circle.y = 20;
	win->circle.vx = 1;
	win->circle.vy = 1;	
	win->circle.rad = 15;
	mlx_hook(win->win_ptr, 17, 0, &ft_exit, (void*)win);
	mlx_loop_hook(win->mlx_ptr, &circle_moving, win);
}
