/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:22:37 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/31 14:22:37 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_exit(void)
{
	exit(EXIT_FAILURE);
}

void	error(char c)
{
	if (c == 'm')
		ft_putstr("malloc error\n");
	else if (c == 'w')
		ft_putstr("windows_open_error\n");
	else if (c == 'a')
		ft_putstr("usage:   ./fdf [map_name]\n");
	else if (c == 'r')
		ft_putstr("map error\n");
	else if (c == 'o')
		ft_putstr("open error\n");
	fdf_exit();
}
