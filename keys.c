/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:52:05 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/31 13:52:06 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_reboot(int key, t_win *win)
{
	if (key == KEY_ESC || key == KEY_ENTER)
		exit(1);
	else if (key == KEY_C)
		ft_bzero(win->ptr, HEIGHT * WIDTH * 4);
}

void	ft_motion(int key, t_win *win)
{
	if (key == KEY_RIGHT)
		motion_use(win, MOVE_RIGHT, 0, 0);
	if (key == KEY_LEFT)
		motion_use(win, MOVE_LEFT, 0, 0);
	if (key == KEY_UP)
		motion_use(win, 0, MOVE_UP, 0);
	if (key == KEY_DOWN)
		motion_use(win, 0, MOVE_DOWN, 0);
}

void	ft_scale(int key,t_win *win)
{

}

void	ft_color_switcher(int key,t_win *win)
{

}

int what_key(int key, t_win *win)
{
	ft_reboot(key, win);
	ft_motion(key, win);
	ft_scale(key, win);
	ft_color_switcher(key, win);
	prepare_draw(win);
	return (0);
}