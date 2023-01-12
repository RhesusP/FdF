/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:34:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/11 23:44:54 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	is_extension_bad(char *str)
{
	char	*extension;
	int		i;

	i = 0;
	extension = ft_strrchr(str, '.');
	if (!extension)
		return (1);
	if (ft_strncmp(".fdf", extension, 4) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cell	**lst;
	int		x_len;
	int		y_len;

	if (argc != 2 || is_extension_bad(argv[1]))
	{
		ft_putendl_fd("[!] USAGE: ./fdf [FDF_MAP]", 2);
		return (0);
	}
	lst = parse_file(argv[1], &x_len, &y_len);
	if (!lst)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	draw_map(lst, x_len, y_len);
	return (0);
}
