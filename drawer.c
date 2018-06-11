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
}

static void		draw_point(t_coord *cd, t_win *win, int color)
{
	int i;

	i = ((int)cd->x * 4) + ((int)cd->y * win->size_line);
	win->ptr[i] = color;
	win->ptr[++i] = color >> 8;
	win->ptr[++i] = color >> 16;
}

void			ft_line_draw(t_win *win, t_coord cd1, t_coord cd2)
{
	int		i;
	double	buff[5];
	double	cp_err;
	int		state;

	if (cd1.x < 0 && cd1.x > WIDTH && cd1.y < 0 && cd1.y > HEIGHT)
		return ;
	get_buff(buff, cd1, cd2);
	state = 1;
	while ((state == 1) && !((int)cd1.x == (int)cd2.x && (int)cd1.y == (int)cd2.y))
	{
		if (cd1.x >= 0 && cd1.x <= WIDTH && cd1.y >= 0 && cd1.y <= HEIGHT)
			draw_point(&cd1, win, 0x0D6386);
		cp_err = buff[4];
		state = 0;
		if (cp_err > -buff[0] && (int)cd1.x != (int)cd2.x)
		{
			buff[4] -= buff[1];
			cd1.x += buff[2];
			state = 1;
		}
		if (cp_err < buff[1] && (int)cd1.y != (int)cd2.y)
		{
			buff[4] += buff[0];
			cd1.y += buff[3];
			state = 1;			
		}
		i = 0;
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
	char *x;
	char *y;

	x = ft_itoa(win->center.x);
	y = ft_itoa(win->center.y);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
	draw_image(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	if (win->mouse.move_mod == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, PINK, "MODE: MOVING");
	else
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, PINK, "MODE: SCALING");
	if (win->mouse.mouse_center == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 60, PINK, "CENTER: MOUSE POSITION");
	else
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 60, PINK, "CENTER: CENTER MAP");	
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 15, PINK, "press [SHIFT] to change mod");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 30, RED, "X: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 30, GREEN, x);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 45, RED, "Y: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 45, GREEN, y);
	free(x);
	free(y);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}
