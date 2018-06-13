/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:54:57 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/11 16:54:57 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check(t_win *win)
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = i;
		if (win->pas[j] == 0)
		{
			while (j < 6)
				if (win->pas[j++] == 1)
					return (0);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (win->pas[i] == 1 && i < 6)
	{
		j++;
		i++;
	}
	if (j == 6)
		return (2);
	return (1);
}

void		pasx(int key, t_win *win)
{
	int i;

	i = 0;
	if (key == KEY_UP)
		win->pas[0] = 1;
	if (key == KEY_DOWN)
		win->pas[1] = 1;
	if (key == KEY_LEFT)
		win->pas[2] = 1;
	if (key == KEY_RIGHT)
		win->pas[3] = 1;
	if (key == KEY_B)
		win->pas[4] = 1;
	if (key == KEY_A)
		win->pas[5] = 1;
	if (check(win) == 1)
		return ;
	else if (check(win) == 2)
		pasx_active(win);
	while (i < 6)
		win->pas[i++] = 0;
}
