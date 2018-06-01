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
** узнать как захватывать зажатую клавишу
** ответ:
** хуй пойми как...
**
** рекурсивно записывать координаты для прибавки производительности???
**
**
** itoabase для манипуляции с цветами
*/
int main(int ac, char **av)
{
   	t_win *win;

	if (ac != 2)
		return (write(1, "error\n", 6));
	win = (t_win*)malloc(sizeof(t_win));
	win->name = ft_strdup(av[1]);
	if ((reader(win)) == -1)
		return(write(1, "reader_error\n", 13));

	win->x0 = 20;
	win->y0 = 20;
	win->img_x = 0;
	win->img_y = 0;	

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, win->name);

	mlx_hook(win->win_ptr, 2, 0, &what_key, (void*)win);
	mlx_loop(win->mlx_ptr);
	return (1);
}
