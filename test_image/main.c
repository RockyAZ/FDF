/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:38:02 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/23 11:38:03 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_line(t_win *win, int x0, int y0, int x1, int y1, int color)
{
	int i;
	int dx = ft_abs(x1-x0);
	int dy = ft_abs(y1-y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy);//поделить на 2?->    ) / 2;
	int cp_err;

	while(x0 <= x1 && y0 <= y1)
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
}

int print(int key, t_win *win)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (key == 53 || key == 36)
		exit(1);
	if (key == 8)
		ft_bzero(win->ptr, HEIGHT * WIDTH * 4);
	if (key == 15)
	{
		while (i <= HEIGHT * WIDTH * 4)
		{
			win->ptr[i] = 0;
			win->ptr[++i] = 0;
			win->ptr[++i] = 255;
			i += 2;
		}
	}
	if (key == 5)
	{
		while (i <= HEIGHT * WIDTH * 4)
		{
			win->ptr[i] = 0;
			win->ptr[++i] = 255;
			win->ptr[++i] = 0;
			i += 2;
		}
	}
	if (key == 11)
	{
		while (i <= HEIGHT * WIDTH * 4)
		{
			win->ptr[i] = 255;
			win->ptr[++i] = 0;
			win->ptr[++i] = 0;
			i += 2;
		}
	}
	ft_line(win, 0, 0, WIDTH, HEIGHT, WHITE);
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	return (0);
}

int main(int ac, char **av)
{
   	t_win *win;

	win = (t_win*)malloc(sizeof(t_win));
	win->fd = open(av[1], O_RDONLY);
//	reader(win);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "DEMO");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, WHITE, "RED - 'R'");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 20, WHITE, "GREEN - 'G'");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 40, WHITE, "BLUE - 'B'");
    win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
    win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
	printf("bpp:%d\n", win->bpp);
	printf("size_line:%d\n", win->size_line);
	printf("endian:%d\n", win->endian);
	
	mlx_key_hook(win->win_ptr, print, (void*)win);
	mlx_loop(win->mlx_ptr);
	return (1);
}
