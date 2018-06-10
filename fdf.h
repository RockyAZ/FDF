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

# define WIDTH 1400
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
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_SHIFT 257

# define KEY_ESC 53
# define KEY_R 15
# define KEY_G 5
# define KEY_B 11
# define KEY_ENTER 36
# define KEY_C 8

# define MOUSE_SCROLL_RIGHT 6
# define MOUSE_SCROLL_LEFT 7
# define MOUSE_SCROLL_UP 5
# define MOUSE_SCROLL_DOWN 4

# define MOVE_KEY 100
# define MOVE_MOUSE 37

# define MOVE_IN 1.1
# define MOVE_OUT 0.9

# define ANGLE_X M_PI / 50
# define ANGLE_Y M_PI / 50
# define ANGLE_Z M_PI / 50

# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
	double			s;
	double			color;
}					t_coord;

typedef struct		s_mouse
{
	int				x;
	int				y;
	int				button_down;
	int				move_mod;
}					t_mouse;

typedef struct		s_matrix
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
}					t_matrix;
/*
** lim_z[0] == min z
** lim_z[1] == max z
*/
typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned char	*ptr;
	t_coord			center;
	t_coord			**coord;
	int				lim_z[2];
	t_mouse			mouse;
	t_matrix		matrix;
	int				len;
	char			*name;
	int				fd;
	int				error;
	int				chars;
	int				lines;
}					t_win;

int					reader(t_win *win);
void				draw_image(t_win *win);
void				clean_img(t_win *win);
void				error(char c);
/*
** mouse and key handlers
*/
void				ft_move(int key, t_win *win, int len);
void				ft_scale(int key, t_win *win);
void				ft_rotate(int key, t_win *win);
/*
** \/\/\/\/\/\/\/\/\/\/\/\/\/\
*/
int					what_key(int key, t_win *win);
void				move_use(double x, double y, double z, t_matrix *mx);
void				scale_use(double s, t_matrix *mx);
void				rotate_x_use(double angle, t_matrix *mx);
void				rotate_y_use(double angle, t_matrix *mx);
void				rotate_z_use(double angle, t_matrix *mx);
/*
** \/\/\/\/\/\/\/\/\/\/\/\/\/\
*/
int					mouse_down(int button, int x, int y, t_win *win);
int					mouse_up(int button, int x, int y, t_win *win);
int					mouse_moving(int x, int y, t_win *win);
/*
** \/\/\/\/\/\/\/\/\/\/\/\/\/\
*/
int					window_prepare(t_win *win);
t_coord				*map_prepare(t_win *win, int x, int y, char *str);
t_coord				get_coord(t_win *win, int x, int y);
void				center_prepare(t_win *win);
void				matrix_prepare(t_win *win);
void				prepare_draw(t_win *win);
/*
** to debuging
*/
void				print_coord(t_win *win, int j);
#endif
