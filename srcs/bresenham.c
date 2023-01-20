/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:59:21 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/20 13:57:07 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	absolute(int *d, int *i)
{
	if (*d < 0)
	{
		*i = -1;
		*d = -(*d);
	}
}

static void	draw_seg_low(t_hook_param param, t_point p1, t_point p2)
{
	int	dy;
	int	yi;
	int	derive;
	int	y;
	int	x;

	dy = p2.y - p1.y;
	yi = 1;
	absolute(&dy, &yi);
	derive = (2 * dy) - (p2.x - p1.x);
	y = p1.y;
	x = p1.x;
	while (x < p2.x)
	{
		mlx_pixel_put(*(param.mlx), *(param.win), x, y, *(param.col));
		if (derive > 0)
		{
			y += yi;
			derive += 2 * (dy - (p2.x - p1.x));
		}
		else
			derive += 2 * dy;
		x++;
	}
}

static void	draw_seg_high(t_hook_param param, t_point p1, t_point p2)
{
	int	dx;
	int	xi;
	int	derive;
	int	y;
	int	x;

	dx = p2.x - p1.x;
	xi = 1;
	absolute(&dx, &xi);
	derive = (2 * dx) - (p2.y - p1.y);
	y = p1.y;
	x = p1.x;
	while (y < p2.y)
	{
		mlx_pixel_put(*(param.mlx), *(param.win), x, y, *(param.col));
		if (derive > 0)
		{
			x += xi;
			derive += 2 * (dx - (p2.y - p1.y));
		}
		else
			derive += 2 * dx;
		y++;
	}
}

void	ft_draw_seg(t_hook_param param, t_point p1, t_point p2)
{
	if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			draw_seg_low(param, p2, p1);
		else
			draw_seg_low(param, p1, p2);
	}
	else
	{
		if (p1.y > p2.y)
			draw_seg_high(param, p2, p1);
		else
			draw_seg_high(param, p1, p2);
	}
}
