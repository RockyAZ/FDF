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

# define WIDTH 1800
# define HEIGHT 1200

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

# define MOVE_UP -100
# define MOVE_DOWN 100
# define MOVE_LEFT -100
# define MOVE_RIGHT 100

# define MOVE_IN 1.1
# define MOVE_OUT 0.9

# include "../../fdf/libft/includes/libft.h"
# include <mlx.h>
# include <math.h>//#define M_PI == 3.14
# include <fcntl.h>
#include <stdio.h>
#define	EXIT_SUCCESS	0
typedef struct	s_coord
{
	double 		x;
	double 		y;
	double 		z;
    double		s;
	double		color;
}				t_coord;

typedef struct s_win
{
    void       *mlx_ptr;
    void       *win_ptr;

    void       *img_ptr;
    int        bpp;
    int        size_line;
    int        endian;
    char       *ptr;

	t_coord		**coord;

    char		*name;
    int        fd;
    int        error;
    int        chars;
    int        lines;
    int        **map_coord;
    int        color;
}              t_win;

typedef struct s_matrix
{
    double			a1;
    double			a2;
    double			a3;
    double			a4;
    double			b1;
    double			b2;
    double			b3;
    double			b4;
    double			c1;
    double			c2;
    double			c3;
    double			c4;
    double			d1;
    double			d2;
    double			d3;
    double			d4;
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
void			draw_image(t_win *win);
void			clean_img(t_win *win);
void			error(char c);


int				what_key(int key, t_win *win);
t_matrix		*move_use(t_win *win, double x, double y, double z);

int				window_prepare(t_win *win);
int				map_prepare(t_win *map);


#endif
