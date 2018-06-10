/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:14:43 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/06 19:14:43 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_down(int button, int x, int y, t_win *win)
{//printf("1::%d\n\n", win->mouse.button_down);
	win->mouse.x = x;
	win->mouse.y = y;
	matrix_prepare(win);
	if (button == MOUSE_SCROLL_UP)
			ft_scale(button, win);
	else if (button == MOUSE_SCROLL_DOWN)
			ft_scale(button, win);
	else
		win->mouse.button_down = 1;
	prepare_draw(win);
	return (0);
}

int		mouse_up(int button, int x, int y, t_win *win)
{//printf("2::%d\n\n", win->mouse.button_down);
	win->mouse.button_down = 0;
	return (0);
}

int		mouse_moving(int x, int y, t_win *win)
{//printf("3::%d\n", win->mouse.button_down);
//write(1, "3\n", 2);

	matrix_prepare(win);
	if (win->mouse.button_down && win->mouse.move_mod == 1)
	{
//write(1, "AAA\n", 4);
		if (win->mouse.x > x)
			ft_move(KEY_RIGHT, win, -(win->mouse.x - x));
		if (win->mouse.x < x)
			ft_move(KEY_LEFT, win, win->mouse.x - x);
		if (win->mouse.y > y)
			ft_move(KEY_DOWN, win, -(win->mouse.y - y));
		if (win->mouse.y < y)
			ft_move(KEY_UP, win, win->mouse.y - y);
	}
	win->mouse.x = x;
	win->mouse.y = y;
	prepare_draw(win);
	return (0);
}
