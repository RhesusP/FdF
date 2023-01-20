/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:23:35 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/20 13:40:50 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	change_color(t_hook_param *param)
{
	int				colors[6];
	static int		index = 0;
	t_hook_param	p;

	p = *param;
	if (!p.cell || !*(p.cell))
		return ;
	colors[0] = 16777215;
	colors[1] = 11883520;
	colors[2] = 15336857;
	colors[3] = 1376236;
	colors[4] = 10621490;
	colors[5] = 5152573;
	index += 1;
	if (index > 5)
		index = 0;
	*(p.col) = colors[index];
	mlx_clear_window(*(p.mlx), *(p.win));
	link_points(p);
}

static void	zoom(t_hook_param *param)
{
	t_hook_param	p;

	p = *param;
	if (!p.cell || !*(p.cell) || *(p.cell_size) - 10 < 1)
		return ;
	*(p.cell_size) += 10;
	mlx_clear_window(*(p.mlx), *(p.win));
	update_coordinates(p.cell, *(p.cell_size));
	set_altitudes(p.cell, *(p.cell_size));
	link_points(p);
}

static void	unzoom(t_hook_param *param)
{
	t_hook_param	p;

	p = *param;
	if (!p.cell || !*(p.cell))
		return ;
	*(p.cell_size) -= 10;
	mlx_clear_window(*(p.mlx), *(p.win));
	update_coordinates(p.cell, *(p.cell_size));
	set_altitudes(p.cell, *(p.cell_size));
	link_points(p);
}

void	quit(t_hook_param *param)
{
	t_hook_param	p;

	p = *param;
	mlx_clear_window(*(p.mlx), *(p.win));
	ft_free_cells_lst(param);
	exit(0);
}

int	deal_key(int key, void *param)
{
	if (key == 125)
		translation_down(param);
	else if (key == 126)
		translation_up(param);
	else if (key == 123)
		translation_left(param);
	else if (key == 124)
		translation_right(param);
	else if (key == 8)
		change_color(param);
	if (key == 257)
		zoom(param);
	else if (key == 256)
		unzoom(param);
	else if (key == 53)
		quit(param);
	return (0);
}
