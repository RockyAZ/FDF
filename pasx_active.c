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

void drawcircle(int x0, int y0, int radius, t_win *win)
{
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 + x, y0 + y, WHITE);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 + y, y0 + x, WHITE);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 - y, y0 + x, WHITE);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 - x, y0 + y, WHITE);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 - x, y0 - y, WHITE);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 - y, y0 - x, WHITE);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 + y, y0 - x, WHITE);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x0 + x, y0 - y, WHITE);
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

void	pasx_active(t_win *win)