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
** не, я все таки понял как!!!
**
** рекурсивно записывать координаты???
**
**
** itoabase для манипуляции с цветами
*/
int main(int ac, char **av)
{
   	t_win *win;

	if (ac != 2)
		return (write(1, "error\n", 6));
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (write(1, "win_malloc_error\n", 17));
	win->name = av[1];
	if ((reader(win)) == -1)
		return(write(1, "reader_error\n", 13));
	if (!windows_prepare(win))
		return(write(1, "windows_open_error\n", 19));
	mlx_hook(win->win_ptr, 2, 0, &what_key, (void*)win);
	mlx_loop(win->mlx_ptr);
	return (1);
}
