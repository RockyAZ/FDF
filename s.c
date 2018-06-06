
void	ft_line_draw(t_win *win, t_coord cd1, t_coord cd2)
{
	int i;
	double buff[6];
	
	double dx = fabs(cd2.x - cd1.x);
	double dy = fabs(cd2.y - cd1.y);
	double sx = cd1.x < cd2.x ? 1 : -1;
	double sy = cd1.y < cd2.y ? 1 : -1;
	double err = (dx > dy ? dx : -dy) / 2;										//поделить на 2?->    ) / 2;
	double cp_err;
//	if (cd1.x < 0 || cd1.x >= WIDTH || cd1.y < 0 || cd1.y >= HEIGHT || cd2.x < 0 || cd2.x >= WIDTH || cd2.y < 0 || cd2.y >= HEIGHT)
//		return ;
			get_buff(buff, cd1, cd2);
	while (cd1.x <= cd2.x && cd1.y <= cd2.y)
	{
		i = (cd1.x * 4) + (cd1.y * win->size_line);
		win->ptr[i] = 0;
		win->ptr[++i] = 120;
		win->ptr[++i] = 0;
		cp_err = err;
		if (cp_err > -dx)
		{
			err -= dy;
			cd1.x += sx;
		}
		if (cp_err < dy)
		{
			err += dx;
			cd1.y += sy;
		}
	}
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
//	ft_bzero(win->ptr, (WIDTH * HEIGHT) * 4);
}





void	ft_line_draw(t_win *win, t_coord cd1, t_coord cd2)
{
	int i;
	double buff[6];
	
	double dx = fabs(cd2.x - cd1.x);
	double dy = fabs(cd2.y - cd1.y);
	double sx = cd1.x < cd2.x ? 1 : -1;
	double sy = cd1.y < cd2.y ? 1 : -1;
	double err = (dx > dy ? dx : -dy) / 2;										//поделить на 2?->    ) / 2;
	double cp_err;
//	if (cd1.x < 0 || cd1.x >= WIDTH || cd1.y < 0 || cd1.y >= HEIGHT || cd2.x < 0 || cd2.x >= WIDTH || cd2.y < 0 || cd2.y >= HEIGHT)
//		return ;
			get_buff(buff, cd1, cd2);
	while (cd1.x <= cd2.x && cd1.y <= cd2.y)
	{
		i = (cd1.x * 4) + (cd1.y * win->size_line);
		win->ptr[i] = 0;
		win->ptr[++i] = 120;
		win->ptr[++i] = 0;
		cp_err = err;
		if (cp_err > -buff[0])
		{
			err -= buff[1];
			cd1.x += buff[2];
		}
		if (cp_err < buff[1])
		{
			err += buff[0];
			cd1.y += buff[3];
		}
	}
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
//	ft_bzero(win->ptr, (WIDTH * HEIGHT) * 4);
}