/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:03:33 by cbignon           #+#    #+#             */
/*   Updated: 2021/02/01 15:17:58 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strclen(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*st;

	i = 0;
	st = (char*)s;
	while (i < n)
	{
		st[i] = c;
		i++;
	}
	return ((void*)s);
}

int		free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

void	*try_to_malloc(char *src, int size)
{
	char	*dest;

	dest = NULL;
	if (!(dest = malloc(sizeof(char) * size)))
		return ((void*)(unsigned long long)free_str(&src));
	return (dest);
}

t_list	multi_fd_read(char **multi_keep, int fd, char *buf)
{
	t_list		res;

	if (!(multi_keep = (char**)malloc(sizeof(char*) * 1024)))
	{
		res.str = NULL;
		return (res);
	}
	while ((res.in_buf = read(fd, buf, BUFFER_SIZE)) > 0 && is_this_line(multi_keep[fd]) == 0)
	{
		multi_keep[fd] = ft_join(multi_keep[fd], buf, res.in_buf);
		res.str = multi_keep[fd];
		return (res);
	}
	return (res);
}