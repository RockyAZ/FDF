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

void	matrix_scaling_plus(t_win *win, t_matrix *matrix)
{
	matrix->a += 1;
	matrix->e += 1;
	matrix->i += 1;
	matrix->s += 1;


}

void	matrix(t_win *win)
{
	t_matrix *mx;

	mx = (t_matrix*)malloc(sizeof(t_matrix));
	if ()

}