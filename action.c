/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:13:53 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/31 14:13:53 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*rotate_z_use(double angle)
{
	t_matrix *mx;

	mx = matrix_prepare();
	mx->a1 = cos(angle);
	mx->a2 = -sin(angle);
	mx->b1 = sin(angle);
	mx->b2 = cos(angle);
	mx->c3 = 1;
//	mx->d4 = 1;
	return (mx);
}


t_matrix	*rotate_y_use(double angle)
{
	t_matrix *mx;

	mx = matrix_prepare();
	mx->a1 = cos(angle);
	mx->a3 = sin(angle);
	mx->b2 = 1;
	mx->c1 = -sin(angle);
	mx->c3 = cos(angle);
//	mx->d4 = 1;
	return (mx);
}


t_matrix	*rotate_x_use(double angle)
{
	t_matrix *mx;

	mx = matrix_prepare();
	mx->a1 = 1;
	mx->b2 = cos(angle);
	mx->b3 = -sin(angle);
	mx->c2 = sin(angle);
	mx->c3 = cos(angle);
//	mx->d4 = 1;
	return (mx);
}


t_matrix	*scale_use(double s)
{
	t_matrix *mx;

	mx = matrix_prepare();
	mx->a1 = s;
	mx->b2 = s;
	mx->c3 = s;
	mx->d4 = 1;
	return (mx);
}

t_matrix	*move_use(double x, double y, double z)
{
	t_matrix *mx;

	mx = matrix_prepare();
	mx->a1 = 1;
	mx->b2 = 1;
	mx->c3 = 1;
	mx->d4 = 1;
	mx->a4 = x;
	mx->b4 = y;
	mx->c4 = z;
	return (mx);
}
