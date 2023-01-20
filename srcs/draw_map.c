/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:22:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/20 14:50:29 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	setup_mlx(void **mlx_ptr, void **win_ptr, t_hook_param *param)
{
	if (!*mlx_ptr || !*win_ptr)
		exit(EXIT_FAILURE);
	param->mlx = mlx_ptr;
	param->win = win_ptr;
	mlx_do_key_autorepeaton(*(param->mlx));
	mlx_hook(*(param->win), 2, (1L << 0), deal_key, param);
	mlx_hook(*(param->win), 17, (1L << 2), ft_free_cells_lst, param);
}

void	draw_map(t_cell **lst, int x_len, int y_len)
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				cell_size;
	t_hook_param	param;
	int				color;

	color = 16777215;
	cell_size = 0;
	param.cell = lst;
	param.cell_size = &cell_size;
	param.x_len = x_len;
	param.col = &color;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1300, 800, "FdF");
	setup_mlx(&mlx_ptr, &win_ptr, &param);
	if (*lst)
	{
		cell_size = set_origin_point(lst, x_len, y_len);
		param.cell_size = &cell_size;
		update_coordinates(lst, *(param.cell_size));
		set_altitudes(lst, *(param.cell_size));
		link_points(param);
	}
	mlx_loop(*(param.mlx));
}
