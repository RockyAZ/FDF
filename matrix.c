/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:42:31 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/29 12:42:32 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*matrix_scaling_plus(int scaling_size)
{
	t_matrix *matrix;

	if ((matrix = (t_matrix*)malloc(sizeof(t_matrix))) == NULL)
		error('m');
	matrix->a1 = scaling_size;
	matrix->b2 = scaling_size;
	matrix->c3 = scaling_size;
	matrix->d4 = 1;


}

void	matrix(t_win *win)
{
	t_matrix *mx;

	mx = (t_matrix*)malloc(sizeof(t_matrix));
	if ()

}