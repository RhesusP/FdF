/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:29:27 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/20 13:04:58 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

t_cell	*ft_create_cell(int x, int y, int z)
{
	t_cell	*res;

	res = malloc(sizeof(t_cell));
	if (!res)
		return (0);
	res->point.x = x;
	res->point.y = y;
	res->point.z = z;
	res->next = 0;
	res->prev = 0;
	return (res);
}

t_cell	*ft_get_last_cell(t_cell **lst)
{
	if (*lst == 0)
		return (0);
	return ((*lst)->prev);
}

void	ft_add_cell_back(t_cell **lst, t_cell *new)
{
	t_cell	*last;

	if (*lst == 0)
	{
		*lst = new;
		new->prev = new;
		return ;
	}
	last = ft_get_last_cell(lst);
	last->next = new;
	new->prev = last;
	new->next = 0;
	(*lst)->prev = new;
}

int	ft_free_cells_lst(t_hook_param *p)
{
	t_cell	**lst;
	t_cell	*current;
	t_cell	*next;

	lst = p->cell;
	if (lst)
	{
		lst = p->cell;
		current = *lst;
		while (current)
		{
			next = current->next;
			free (current);
			current = next;
		}
	}
	free(lst);
	exit(EXIT_SUCCESS);
	return (0);
}
