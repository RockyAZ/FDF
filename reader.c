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

static void	ft_arrr_del(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	count_line(t_win *win)
{
	char	*line;
	int		char_buf;

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
	win->len = (0.5 * ft_min(WIDTH, HEIGHT)) / ft_min(win->chars, win->lines);
	return (1);
}

/*
** RECURSIVE???
*/

int			reader(t_win *win)
{
	char	**arr;
	char	*line;
	int		i;
	int		j;

	if (((win->fd = open(win->name, O_RDONLY)) < 0) || !(count_line(win)))
		error('o');
	i = 0;
	win->coord = (t_coord**)malloc(sizeof(t_coord) * (win->lines * win->chars));
	while (get_next_line(win->fd, &line))
	{
		arr = ft_strsplit(line, ' ');
		j = 0;
		while (arr[j])
		{
			win->coord[(i * win->chars) + j] = map_prepare(win, j, i, arr[j]);
			j++;
		}
		free(line);
		ft_arrr_del(arr);
		i++;
	}	
	return (1);
}
