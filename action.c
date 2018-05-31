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

t_matrix	*motion_use(t_win *win, double x, double y, double z)
{
	t_matrix *mx;

	if ((mx = (t_matrix*)malloc(sizeof(t_matrix))) == NULL)
		error_malloc();
	mx->a1 = 1;
	mx->b2 = 1;
	mx->c3 = 1;
	mx->d4 = 1;
	mx->a4 = x;
	mx->b4 = y;
	mx->c4 = z;
	return (mx);
}