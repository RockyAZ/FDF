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
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_R 15
# define KEY_G 5
# define KEY_B 11
# define KEY_ENTER 36
# define KEY_C 8
# define KEY_PLUS 69
# define KEY_MINUS 78

# define LENGTH 10

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
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
    int        x0;
    int        y0;
    int        x1;
    int        y1;
	int			img_x;
	int			img_y;	
    int        z;
    int        wx;
    int        hy;
    int        fd;
    int        error;
    int        chars;
    int        lines;
    int        **map_coord;
    int        check;
    int        color;
}              t_win;

typedef struct s_matrix
{
    double			a;
    double			b;
    double			c;
    double			p;
    double			d;
    double			e;
    double			f;
    double			q;
    double			g;
    double			h;
    double			i;
    double			r;
    double			l;
    double			m;
    double			n;
    double			s;
}				t_matrix;
/*
typedef struct s_image
{
    int        bpp;
    int        size_line;
    int        endian;
}
*/

int				reader(t_win *win);
void			drawer(t_win *win);
void            clean_img(t_win *win);
#endif
