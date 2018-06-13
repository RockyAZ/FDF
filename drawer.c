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

void			get_buff(double *buff, t_coord cd1, t_coord cd2)
{
	buff[0] = fabs(cd1.x - cd2.x);
	buff[1] = fabs(cd1.y - cd2.y);
	buff[2] = cd1.x < cd2.x ? 1 : -1;
	buff[3] = cd1.y < cd2.y ? 1 : -1;
	buff[4] = (buff[0] > buff[1] ? buff[0] : -buff[1]);
	buff[6] = 1;
}

static void		draw_point(t_coord *cd, t_win *win, int color)
{
	int i;

	i = ((int)cd->x * 4) + ((int)cd->y * win->size_line);
	win->ptr[i] = color;
	win->ptr[++i] = color >> 8;
	win->ptr[++i] = color >> 16;
}

void			ft_line_draw(t_win *win, t_coord v1, t_coord v2)
{
	double	buff[7];

	if (v1.x < 0 && v1.x > WIDTH && v1.y < 0 && v1.y > HEIGHT)
		return ;
	get_buff(buff, v1, v2);
	while (buff[6] == 1 && !((int)v1.x == (int)v2.x && (int)v1.y == (int)v2.y))
	{
		if (v1.x >= 0 && v1.x <= WIDTH && v1.y >= 0 && v1.y <= HEIGHT)
			draw_point(&v1, win, v1.color);
		buff[5] = buff[4];
		buff[6] = 0;
		if (buff[5] > -buff[0] && (int)v1.x != (int)v2.x)
		{
			buff[4] -= buff[1];
			v1.x += buff[2];
			buff[6] = 1;
		}
		if (buff[5] < buff[1] && (int)v1.y != (int)v2.y)
		{
			buff[4] += buff[0];
			v1.y += buff[3];
			buff[6] = 1;
		}
	}
}

void			draw_image(t_win *win)
{
	int		x;
	int		y;
	t_coord	v;

	y = 0;
	while (y < win->lines)
	{
		x = 0;
		while (x < win->chars)
		{
			v = get_coord(win, x, y);
			if (x + 1 < win->chars)
				ft_line_draw(win, v, get_coord(win, x + 1, y));
			if (y + 1 < win->lines)
				ft_line_draw(win, v, get_coord(win, x, y + 1));
			x++;
		}
		y++;
	}
}

void			prepare_draw(t_win *win)
{
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr,
	&win->bpp, &win->size_line, &win->endian);
	draw_image(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	str_out(win);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}
