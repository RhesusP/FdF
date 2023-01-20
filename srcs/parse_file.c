/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:39 by cbernot           #+#    #+#             */
/*   Updated: 2023/01/20 14:05:09 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	ft_free_tab(char **tab)
{
	int		i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int	extract_line(t_cell **lst, char *line, int *y_len)
{
	char		**tab;
	int			len;
	t_cell		*new;
	static int	y = 0;
	static int	prev_len = -1;

	tab = ft_split(line, ' ');
	len = 0;
	while (tab[len] && ft_strncmp(tab[len], "\n", 1) != 0)
	{
		new = ft_create_cell(len, y, ft_atoi(tab[len]));
		ft_add_cell_back(lst, new);
		len++;
	}
	ft_free_tab(tab);
	free(tab);
	if (prev_len == -1)
		prev_len = len;
	else if (prev_len != -1 && prev_len != len)
		return (0);
	y++;
	*y_len = y;
	return (len);
}

static int	open_file(t_cell **lst, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		free(lst);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

t_cell	**parse_file(char *path, int *x_len, int *y_len)
{
	char	*line;
	int		fd;
	t_cell	**lst;

	lst = malloc(sizeof(t_cell *));
	if (!lst)
		return (0);
	*lst = 0;
	fd = open_file(lst, path);
	line = "";
	*x_len = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			*x_len = extract_line(lst, line, y_len);
			if (*x_len == 0)
				return (0);
		}
		free(line);
	}
	close(fd);
	return (lst);
}
