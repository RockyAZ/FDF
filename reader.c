/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:41:40 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/16 12:41:46 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int count_chars(t_win *win, char *line)
{
    int x;
    char **arr;

    arr = ft_strsplit(line, ' ');
    x = 0;
    while (arr[x])
    {
        free(arr[x]);
        x++;
    }
    if (win->chars == 0)
        win->chars = x;
    else
        if (win->chars != x)
            return (0);
    free(arr);
    return (1);
}
*/
int count_line(t_win *win)
{
	char *line;
	int char_buf;

	win->chars = 0;
	win->lines = 0;
	char_buf = 0;
	win->fd = open(win->name, O_RDONLY);
	while (get_next_line(win->fd, &line) > 0)
	{
		if (win->chars != 0)
		{
			if (ft_count_words(line) != win->chars)
				return (0);
		}
		else
			win->chars = ft_count_words(line);
		win->lines++;
		free(line);
	}
	close(win->fd);
	win->fd = open(win->name, O_RDONLY);
	return (1);
}
/*
** RECURSIVE???
*/
int reader(t_win *win)
{
	char **arr;
	char *line;
	int i;
	int j;

	if ((win->fd = open(win->name, O_RDONLY)) < 0)
		error('o');
	if (!(count_line(win)))
		return (-1);
	i = 0;
	win->map_coord = (int**)ft_memalloc(sizeof(int*) * win->lines);
	while (get_next_line(win->fd, &line))
	{
		arr = ft_strsplit(line, ' ');
		j = 0;
		win->map_coord[i] = (int*)ft_memalloc(sizeof(int) * win->chars);
		while (arr[j])
		{
			win->map_coord[i][j] = ft_atoi(arr[j]);
			j++;
		}
		free(line);
		i++;
	}
	return (1);
}
