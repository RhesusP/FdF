/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:18:54 by cbernot           #+#    #+#             */
/*   Updated: 2022/12/17 14:28:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
//# include <unistd.h>
//# include <stdlib.h>
# include "./../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char	*get_next_line(int fd);
/*
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
*/
void	*ft_free_stash(char **stash, int create_line);

#endif