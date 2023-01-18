/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:16:01 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/18 14:33:15 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	translation_down(t_hook_param *param)
{
	t_cell	**lst;
	t_cell	*current;
	t_hook_param	p;

	p = *param;
	if (!p.cell)
		return ;
	lst = p.cell;
	current = *lst;
	while (current)
	{
		current->graph_y += 2;
		current = current->next;
	}
	mlx_clear_window(*(p.mlx_ptr), *(p.win_ptr));
	update_coordinates(p.cell, *(p.cell_size), p.x_len);
	set_altitudes(p.cell, *(p.cell_size));
	link_points(p);
}

void	translation_up(t_hook_param *param)
{
	t_cell	**lst;
	t_cell	*current;
	t_hook_param	p;

	p = *param;
	if (!p.cell)
		return ;
	lst = p.cell;
	current = *lst;
	while (current)
	{
		current->graph_y -= 2;
		current = current->next;
	}
	mlx_clear_window(*(p.mlx_ptr), *(p.win_ptr));
	update_coordinates(p.cell, *(p.cell_size), p.x_len);
	set_altitudes(p.cell, *(p.cell_size));
	link_points(p);
}

void	translation_right(t_hook_param *param)
{
	t_cell	**lst;
	t_cell	*current;
	t_hook_param	p;

	p = *param;
	if (!p.cell)
		return ;
	lst = p.cell;
	current = *lst;
	while (current)
	{
		current->graph_x += 2;
		current = current->next;
	}
	mlx_clear_window(*(p.mlx_ptr), *(p.win_ptr));
	update_coordinates(p.cell, *(p.cell_size), p.x_len);
	set_altitudes(p.cell, *(p.cell_size));
	link_points(p);
}

void	translation_left(t_hook_param *param)
{
	t_cell	**lst;
	t_cell	*current;
	t_hook_param	p;

	p = *param;
	if (!p.cell)
		return ;
	lst = p.cell;
	current = *lst;
	while (current)
	{
		current->graph_x -= 2;
		current = current->next;
	}
	mlx_clear_window(*(p.mlx_ptr), *(p.win_ptr));
	update_coordinates(p.cell, *(p.cell_size), p.x_len);
	set_altitudes(p.cell, *(p.cell_size));
	link_points(p);
}
