/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:18:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/11 21:10:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

t_point	ft_create_point(int x, int y, int z)
{
	t_point	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_point	ft_get_angle_point(t_point point, int deg, int cell_size)
{
	t_point	res;

	res.x = point.x + (cell_size * cos(deg * M_PI / 180));
	res.y = point.y + (cell_size * sin(deg * M_PI / 180));
	res.z = point.z;
	return (res);
}

int	set_origin_point(t_cell **lst, int x_len, int y_len)
{
	int	cell_size;
	int	origin;

	if (800 / x_len < 800 / y_len)
		cell_size = 800 / (x_len + 2);
	else
		cell_size = 800 / (y_len + 2);
	origin = (1300 / 2) + (cell_size * y_len) - (cell_size * x_len);
	(*lst)->graph_x = origin;
	(*lst)->graph_y = 10;
	return (cell_size);
}
