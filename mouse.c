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

int		what_mouse(int button, int x, int y, t_win *win)
{
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
