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
{write(1, "1\n", 2);
//printf("%d\n\n", win->mouse.button_down);
	win->mouse.button_down = 1;
	win->mouse.x = x;
	win->mouse.y = y;	
	if (button == MOUSE_SCROLL_UP)
	{
		if (win->mouse.move_mod == -1)
			ft_scale(button, win);
		else
			ft_move(button, win, MOVE_MOUSE);
	}
	if (button == MOUSE_SCROLL_DOWN)
	{
		if (win->mouse.move_mod == -1)
			ft_scale(button, win);
		else
			ft_move(button, win, MOVE_MOUSE);
	}
	if (button == MOUSE_SCROLL_RIGHT)
		ft_move(button, win, MOVE_MOUSE);
	if (button == MOUSE_SCROLL_LEFT)
		ft_move(button, win, MOVE_MOUSE);
	if (win->mouse.move_mod == 1)
		center_prepare(win);
	prepare_draw(win);
	return (0);
}

int		mouse_up(int button, int x, int y, t_win *win)
{//write(1, "2\n", 2);
//printf("%d\n\n", win->mouse.button_down);
	win->mouse.button_down = 0;
	return (0);
}

int		mouse_moving(int button, int x, int y, t_win *win)
{
printf("%d\n", win->mouse.button_down);
//printf("%d\n", win->fd);
	if (win->mouse.button_down && win->mouse.move_mod == 1)
	{
printf("X:%d\nY:%d\n\n", x, y);
		if (win->mouse.x > x)
			ft_move(KEY_RIGHT, win, win->mouse.x - x);
		else if (win->mouse.x < x)
			ft_move(KEY_LEFT, win, win->mouse.x - x);
		else if (win->mouse.y > y)
			ft_move(KEY_DOWN, win, win->mouse.y - y);
		else if (win->mouse.y < y)
			ft_move(KEY_UP, win, win->mouse.y - y);
		win->mouse.x = x;
		win->mouse.y = y;
	}
	return (0);
}
