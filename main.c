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
*/



int print(int key, t_win *win)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_bzero(win->ptr, (WIDTH * HEIGHT) * 4);
/*
** REBOOT
*/
	if (key == KEY_ESC || key == KEY_ENTER)
		exit(1);
	if (key == KEY_C)
		ft_bzero(win->ptr, HEIGHT * WIDTH * 4);
/*
**  ⬆
**⬅   ➡
**  ⬇
**	  
*/
	if (key == KEY_LEFT)
		win->img_x -= 10;
	if (key == KEY_UP)
		win->img_y -= 10;
	if (key == KEY_RIGHT)
		win->img_x += 10;
	if (key == KEY_DOWN)
		win->img_y += 10;
/*
** COLORS
*/
	if (key == KEY_R)
	{
		while (i <= HEIGHT * WIDTH * 4)
		{
			win->ptr[i] = 0;
			win->ptr[++i] = 0;
			win->ptr[++i] = 255;
			i += 2;
		}
	}
	if (key == KEY_G)
	{
		while (i <= HEIGHT * WIDTH * 4)
		{
			win->ptr[i] = 0;
			win->ptr[++i] = 255;
			win->ptr[++i] = 0;
			i += 2;
		}
	}
	if (key == KEY_B)
	{
		while (i <= HEIGHT * WIDTH * 4)
		{
			win->ptr[i] = 255;
			win->ptr[++i] = 0;
			win->ptr[++i] = 0;
			i += 2;
		}
	}
	drawer(win);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, PINK, "RED - 'R'");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 20, PINK, "GREEN - 'G'");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 40, PINK, "BLUE - 'B'");
	return (0);
}
/*
** узнать как захватывать зажатую клавишу
** ответ:
** хуй пойми как...
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

    win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
    win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
	mlx_key_hook(win->win_ptr, &print, (void*)win);
	mlx_loop(win->mlx_ptr);
	return (1);
}
