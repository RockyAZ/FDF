/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:38:02 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/23 11:38:03 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
** переделать под листы?
** во время read записать max Z and min Z
** в day2_fdf пример упрощения больших 16-ричных чисел in da read_point();
*/

/*
** рекурсивно записывать координаты???
**
**
** itoabase для манипуляции с цветами
*/
int main(int ac, char **av)
{
   	t_win *win;

	if (ac != 2)
		error('a');
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		error('m');
	win->name = av[1];
	if ((reader(win)) == -1)
		error('r');
	if (!window_prepare(win))
		error('w');
	center_prepare(win);
	prepare_draw(win);
	mlx_hook(win->win_ptr, 2, 0, &what_key, (void*)win);
	mlx_hook(win->win_ptr, 17, 0, &what_key, (void*)win);
	mlx_hook(win->win_ptr, 4, 0, &what_mouse, (void*)win);//mouse
	mlx_loop(win->mlx_ptr);
	return (1);
}
