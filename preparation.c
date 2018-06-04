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

int		window_prepare(t_win *win)
{
	if (!(win->mlx_ptr = mlx_init()) ||
	!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, win->name)))
		return (0);
	return (1);
}

t_coord	*map_prepare(t_win *win, int x, int y, char *str)
{
	t_coord *coord;

	if (!(coord = (t_coord*)malloc(sizeof(t_coord))))
		error('m');
	coord->x = x * win->len;
	coord->y = y * win->len;
	coord->z = ft_atoi(str);
	return (coord);
}
