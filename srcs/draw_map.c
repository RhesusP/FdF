/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:22:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/12 00:00:08 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

t_point	put_point(t_cell *c, t_cell *first, int cell_size)
{
	t_point	p;
	t_point	temp;

	if (c->next->point.x == 0)
	{
		temp = ft_create_point((*first).graph_x, (*first).graph_y, c->point.z);
		p = ft_get_angle_point(temp, 150, cell_size);
	}
	else if (c->point.x == 0)
	{
		(*first) = *c;
		temp = ft_create_point(c->graph_x, c->graph_y, c->next->point.z);
		p = ft_get_angle_point(temp, 30, cell_size);
	}
	else
	{
		temp = ft_create_point(c->graph_x, c->graph_y, c->next->point.z);
		p = ft_get_angle_point(temp, 30, cell_size);
	}
	return (p);
}

void	update_coordinates(t_cell **lst, int cell_size, int x_len)
{
	t_cell	*curr;
	t_cell	first;
	t_point	p;

	curr = *lst;
	first = **lst;
	while (curr->next)
	{
		p = put_point(curr, &first, cell_size);
		curr->next->graph_x = p.x;
		curr->next->graph_y = p.y;
		curr = curr->next;
	}
}

void	set_altitudes(t_cell **lst, int cell_size)
{
	t_cell	*current;

	current = *lst;
	while (current)
	{
		current->graph_y -= (current->point.z * cell_size * 0.2);
		current = current->next;
	}
}

t_cell	*get_bottom_neighbour(t_cell *cell, int x_len)
{
	t_cell	*neighbour;
	int		i;

	i = 0;
	neighbour = cell;
	while (i < x_len)
	{
		if (neighbour == 0 || neighbour->next == 0)
			neighbour = 0;
		else
			neighbour = neighbour->next;
		i++;
	}
	return (neighbour);
}

void	link_neighbours(t_cell *cell, t_hook_param *param)
{
	int		i;
	t_cell	*nbr;
	t_point	p1;
	t_point	p2;

	if (cell->next && cell->next->point.x > cell->point.x)
	{
		p1 = ft_create_point(cell->graph_x, cell->graph_y, 0);
		p2 = ft_create_point(cell->next->graph_x, cell->next->graph_y, 0);
		ft_draw_seg(param, p1, p2);
	}
	nbr = get_bottom_neighbour(cell, param->x_len);
	if (nbr)
	{
		p1 = ft_create_point(cell->graph_x, cell->graph_y, cell->point.z);
		p2 = ft_create_point(nbr->graph_x, nbr->graph_y, nbr->point.z);
		ft_draw_seg(param, p1, p2);
	}
}

void	link_points(t_hook_param *param)
{
	t_cell	*current;

	current = *(param->cell);
	while (current)
	{
		link_neighbours(current, param);
		current = current->next;
	}
}

void	draw_map(t_cell **lst, int x_len, int y_len)
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				cell_size;
	t_hook_param	*param;

	param = malloc(sizeof(t_hook_param *));
	if (!param)
		return ;
	mlx_ptr = mlx_init();
	mlx_do_key_autorepeaton(mlx_ptr);
	win_ptr = mlx_new_window(mlx_ptr, 1300, 800, "FdF");
	param->cell = lst;
	param->mlx_ptr = mlx_ptr;
	param->win_ptr = win_ptr;
	param->cell_size = 0;
	param->x_len = x_len;
	param->color = 16777215;
	if (*lst)
	{
		cell_size = set_origin_point(lst, x_len, y_len);
		param->cell_size = cell_size;
		update_coordinates(lst, cell_size, x_len);
		set_altitudes(lst, cell_size);
		link_points(param);
	}
	mlx_key_hook(win_ptr, deal_key, param);
	mlx_hook(win_ptr, 17, 0, ft_free_cells_lst, param);
	mlx_loop(mlx_ptr);
}
