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
	if (button == MOUSE_ZOOM_IN)
		what_key(69, win);
	if (button == MOUSE_ZOOM_OUT)
		what_key(78, win);
printf("%d\n", button);
	return (0);
}