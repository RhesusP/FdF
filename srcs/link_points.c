/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:05:33 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/20 14:39:42 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	update_coordinates(t_cell **lst, int cell_size)
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
		current->graph_y -= (current->point.z * cell_size * 0.6);
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

static void	link_neighbours(t_cell *cell, t_hook_param param)
{
	t_cell	*nbr;
	t_point	p1;
	t_point	p2;

	if (cell->next && cell->next->point.x > cell->point.x)
	{
		p1 = ft_create_point(cell->graph_x, cell->graph_y, 0);
		p2 = ft_create_point(cell->next->graph_x, cell->next->graph_y, 0);
		ft_draw_seg(param, p1, p2);
	}
	nbr = get_bottom_neighbour(cell, param.x_len);
	if (nbr)
	{
		p1 = ft_create_point(cell->graph_x, cell->graph_y, cell->point.z);
		p2 = ft_create_point(nbr->graph_x, nbr->graph_y, nbr->point.z);
		ft_draw_seg(param, p1, p2);
	}
}

void	link_points(t_hook_param param)
{
	t_cell	*current;

	current = *(param.cell);
	while (current)
	{
		link_neighbours(current, param);
		current = current->next;
	}
}
