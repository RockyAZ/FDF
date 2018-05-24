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

int count_line(t_win *win)
{
    char *line;

    win->chars = 0;
    win->line = 0;
    win->fd = open(win->name, O_RDONLY);
    while (get_next_line(win->fd, &line) > 0)
    {
        if (!(count_chars(win, line)))
            return (0);
        win->line++;
        free(line);
    }
    close(win->fd);
    win->fd = open(win->name, O_RDONLY);
    return (1);
}

int reader(t_win *win)
{
    char **arr;
    char *line;
    int i;
    int j;

    if (!(count_line(win)))
        return (0);
        i = 0;
    win->map_coord = (int**)ft_memalloc(sizeof(int*) * win->line);
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
        i++;
    }
    return (1);
}
