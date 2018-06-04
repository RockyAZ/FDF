/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:56:07 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/02 18:56:07 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	window_prepare(t_win *win)
{
	if (!(win->mlx_ptr = mlx_init()) ||
	!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, win->name)))
		return (0);
	return (1);
}

int	map_prepare(t_win *win)
{
	return (1);
}
