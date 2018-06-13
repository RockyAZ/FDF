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
	win->ptr[i + 3] = 40;
}

static void	draw_circle(t_win *win, int arr[2], int x, int y)
{
	put_circle(win, arr[0] + x, arr[1] + y, WHITE);
	put_circle(win, arr[0] + y, arr[1] + x, WHITE);
	put_circle(win, arr[0] - y, arr[1] + x, WHITE);
	put_circle(win, arr[0] - x, arr[1] + y, WHITE);
	put_circle(win, arr[0] - x, arr[1] - y, WHITE);
	put_circle(win, arr[0] - y, arr[1] - x, WHITE);
	put_circle(win, arr[0] + y, arr[1] - x, WHITE);
	put_circle(win, arr[0] + x, arr[1] - y, WHITE);
}

void		get_circle(int arr[2], int radius, t_win *win)
{
	int buf[5];

	buf[0] = radius - 1;
	buf[1] = 0;
	buf[2] = 1;
	buf[3] = 1;
	buf[4] = buf[2] - (radius << 1);
	while (buf[0] >= buf[1])
	{
		draw_circle(win, arr, buf[0], buf[1]);
		if (buf[4] <= 0)
		{
			buf[1]++;
			buf[4] += buf[3];
			buf[3] += 2;
		}
		if (buf[4] > 0)
		{
			buf[0]--;
			buf[2] += 2;
			buf[4] += buf[2] - (radius << 1);
		}
	}
}

static int	circle_moving(t_win *win)
{
	int arr[2];

	win->img_ptr = mlx_new_image(win->mlx_ptr, 400, 300);
	win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr,
	&win->bpp, &win->size_line, &win->endian);
	if (win->circle.x - win->circle.rad <= 0)
		win->circle.vx *= -1;
	if (win->circle.x + win->circle.rad >= 400)
		win->circle.vx *= -1;
	if (win->circle.y - win->circle.rad <= 0)
		win->circle.vy *= -1;
	if (win->circle.y + win->circle.rad >= 300)
		win->circle.vy *= -1;
	win->circle.x += 3 * win->circle.vx;
	win->circle.y += 3 * win->circle.vy;
	arr[0] = win->circle.x;
	arr[1] = win->circle.y;
	get_circle(arr, win->circle.rad, win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr_pasx,
	win->img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	return (0);
}

void		pasx_active(t_win *win)
{
	int i;

	i = 0;
	if (win->pasx_active == 1)
		ft_exit();
	win->pasx_active = 1;
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
