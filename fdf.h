/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:19:58 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/13 13:19:59 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1500
# define HEIGHT 1000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PINK 0xFF00FF
# include "libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
#include <stdio.h>
typedef struct s_win
{
    void       *mlx_ptr;
    void       *win_ptr;
    void       *img_ptr;
    int        bpp;
    int        size_line;
    int        endian;
    unsigned char       *ptr;
    void       *xpm;

    char       *name;
    int        x;
    int        y;
    int        z;
    int        wx;
    int        hy;
    int        fd;
    int        error;
    int        chars;
    int        line;
    int        **map_coord;
    int        check;
    int        color;
}              t_win;

/*
typedef struct s_image
{
    int        bpp;
    int        size_line;
    int        endian;
}
*/

int            reader(t_win *win);
int            drawer(t_win *win);
#endif