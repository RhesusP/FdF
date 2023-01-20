/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:38:44 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/20 13:06:40 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../libft/libft.h"
# include "./../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_cell
{
	t_point			point;
	int				graph_x;
	int				graph_y;
	struct s_cell	*prev;
	struct s_cell	*next;

}	t_cell;

typedef struct s_hook_param
{
	t_cell	**cell;
	void	**mlx;
	void	**win;
	int		*cell_size;
	int		x_len;
	int		*col;
}	t_hook_param;

t_cell	**parse_file(char *path, int *x_len, int *y_len);
t_cell	*ft_create_cell(int x, int y, int z);

t_cell	*ft_create_cell(int x, int y, int z);
t_cell	*ft_get_last_cell(t_cell **lst);
void	ft_add_cell_back(t_cell **lst, t_cell *new);
void	ft_printf_list(t_cell **lst);
int		ft_free_cells_lst(t_hook_param *p);

void	ft_draw_seg(t_hook_param param, t_point p1, t_point p2);
void	draw_map(t_cell **lst, int x_len, int y_len);

t_point	ft_get_angle_point(t_point point, int deg, int cell_size);
t_point	ft_create_point(int x, int y, int z);
void	ft_print_point(t_point p);
t_point	put_point(t_cell *c, t_cell *first, int cell_size);

void	translation_down(t_hook_param *p);
void	translation_up(t_hook_param *p);
void	translation_right(t_hook_param *p);
void	translation_left(t_hook_param *p);

int		deal_key(int key, void *param);
void	quit(t_hook_param *param);
int		set_origin_point(t_cell **lst, int x_len, int y_len);
void	link_points(t_hook_param param);
void	set_altitudes(t_cell **lst, int cell_size);
void	update_coordinates(t_cell **lst, int cell_size);

#endif