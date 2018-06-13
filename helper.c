/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:02:58 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/13 13:02:59 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_coord *coord, double z)
{
	if (z < 0)
		coord->color = 0x14ff03;
	else if (z >= 0 && z <= 3)
		coord->color = 0x4dff4a;
	else if (z > 3 && z <= 6)
		coord->color = 0x7aff83;
	else if (z > 6 && z <= 9)
		coord->color = 0xb8ffc4;
	else
		coord->color = 0xedfff2;
	return (coord->color);
}

t_coord	get_coord(t_win *win, int x, int y)
{
	return(*win->coord[(y * win->chars) + x]);
}

void	print_coord(t_win *win, int j)
{
	if (j == 0)
		j = win->lines * win->chars;
	for(int i = 0; i < j; i++)
	{
		printf("x:%f\n", win->coord[i]->x);
		printf("y:%f\n", win->coord[i]->y);
		printf("z:%f\n\n\n", win->coord[i]->z);		
	}
	printf("-----------------\n");
}
