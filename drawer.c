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
 printf("cd1->x%f\n", cd1->x);
 printf("cd1->y%f\n\n", cd1->y);
 printf("cd2->x%f\n", cd2->x);
 printf("cd2->y%f\n\n\n\n", cd2->y);
//	if (cd1->x < 0 || cd1->x >= WIDTH || cd1->y < 0 || cd1->y >= HEIGHT || cd2->x < 0 || cd2->x >= WIDTH || cd2->y < 0 || cd2->y >= HEIGHT)
//		return ;
	while (cd1->x <= cd2->x && cd1->y <= cd2->y)
	{
		i = (cd1->x * 4) + (cd1->y * win->size_line);
		win->ptr[i] = 0;
		win->ptr[++i] = 120;
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
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
//	ft_bzero(win->ptr, (WIDTH * HEIGHT) * 4);
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
				ft_line_draw(win, cd1, win->coord[(y * win->chars) + (x + 1)]);
			if (y + 1 < win->lines)
				ft_line_draw(win, cd1, win->coord[((y + 1)* win->chars) + x]);
			x++;
		}
		y++;
	}
}

void	prepare_draw(t_win *win)
{
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->ptr = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian)1;
	draw_image(win);
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}
